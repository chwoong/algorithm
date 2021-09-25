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
#include<time.h>
using namespace std;

int n,m,k;
vector<int> v;
int p[4000001];
int nex[4000001];

int find(int i){
	if(p[i]==i) return i;
	else return p[i]=find(p[i]);
}

int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	for(int i=0;i<m;i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<m-1;i++){
		nex[v[i]]=v[i+1];
	}
	for(int i=0;i<k;i++){
		int x;
		scanf("%d",&x);
		int num=*lower_bound(v.begin(),v.end(),x+1);
		printf("%d\n",find(num));
		p[num]=nex[find(num)];
	}
	return 0;
}