#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<cmath>
using namespace std;

typedef pair<int,int> P;
int n,size(1);
int sumtree[400010];
int mintree[400010];
vector<int> result;
P query(int l,int r){
	int m(10000),s(0);
	l+=size;
	r+=size;
	while(l<=r){
		if(l%2==1) {
			m=min(m,mintree[l]);
			s+=sumtree[l++];
		}
		if(r%2==0){
			m=min(m,mintree[r]);
			s+=sumtree[r--];
		}
		l/=2; r/=2;
	}
	return P(m,s);
}

void change(int k,int pos){
	pos+=size;
	mintree[pos]=k;
	sumtree[pos]=k;
	for(pos/=2;pos>=1;pos/=2){
		mintree[pos]=min(mintree[pos*2],mintree[pos*2+1]);
		sumtree[pos]=sumtree[pos*2]+sumtree[pos*2+1];
	}
}

int main(){
	cin>>n;
	while(size<n) size*=2;
	for(int i=1;i<=2*size;i++){
		sumtree[i]=0;
		mintree[i]=10000;
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		change(x,i);
	}
	double x=0;
	for(int i=2;i<=n-1;i++){
		P ret=query(i,n);
		double score=(double)(ret.second-ret.first)/(n-i);
		if(score>x){
			x=score;
			vector<int> em;
			swap(result,em);
			result.push_back(i-1);
		}else if(abs(score-x)<1e-9){
			result.push_back(i-1);
		}
	}
	for(int ele:result)
		printf("%d\n",ele);
	return 0;
}