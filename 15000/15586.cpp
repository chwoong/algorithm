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

int n,q;
struct S{
	int u0,v0,w;
	bool operator<(S &tmp)const{
		return w>tmp.w;
	}
};
vector<S> v;
vector<S> query;
int ans[100000];
int p[100001];

int find(int i){
	if(p[i]<0) return i;
	return p[i]=find(p[i]);
}

void merge(int i,int j){
	i=find(i);
	j=find(j);
	if(i==j) return;
	p[i]+=p[j];
	p[j]=i;
}

int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		p[i]=-1;
	for(int i=0;i<n-1;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		v.push_back((S){a,b,c});
	}
	sort(v.begin(),v.end());
	for(int i=0;i<q;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		query.push_back((S){b,i,a});
	}
	sort(query.begin(),query.end());
	int tmp=0;
	for(int i=0;i<q;i++){
		S here=query[i];
		int k=here.w;
		int x=here.u0;
		while(tmp<n-1 && v[tmp].w>=k){
			merge(v[tmp].u0,v[tmp].v0);
			tmp++;
		}
		ans[here.v0]=-p[find(x)];
	}
	for(int i=0;i<q;i++)
		printf("%d\n",ans[i]-1);
	return 0;
}