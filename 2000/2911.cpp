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
int n,m,s(1);
vector<P> v;
int seg[400010];
int num=0;
void update(int pos,int val){
	pos+=s;
	seg[pos]+=val;
	for(pos/=2;pos>=1;pos/=2){
		seg[pos]=min(seg[pos*2],seg[pos*2+1]);
	}
}

int query(int l,int r){
	l+=s;
	r+=s;
	int ret=1000000000;
	while(l<=r){
		if(l%2==1) ret=min(ret,seg[l++]);
		if(r%2==0) ret=min(ret,seg[r--]);
		l/=2;
		r/=2;
	}
	return ret;
}

long long solve(int l,int r){
	if(l==r) return seg[l+s];
	long long ret=0;
	int p=-1;
	for(int i=l;i<=r;i++){
		if(seg[i+s]!=0 && p==-1){
			p=i;
		}
		if((seg[i+s]==0 && p!=-1) ||(i==r && seg[i+s]!=0)){
			if(seg[i+s]==0 && p!=-1) i--;
			num++;
			int x=query(p,i);
			for(int j=p;j<=i;j++) 
				update(j,-x);
			ret+=x;
			ret+=solve(p,i);
			i++;
			p=-1;
		}
	}
	return ret;
}

int main(){
	cin>>n>>m;
	while(s<n) s*=2;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v.push_back(P(a,b));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		update(i,v[i].second);
	}
	cout<<solve(0,n-1);
	return 0;
}