#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;


struct edge{
	int u,v,w;	
}e[200000];
bool operator<(edge a,edge b){return a.w<b.w;}

int p[200000];

int find(int i){
	if(p[i]==i) return i;
	return p[i]=find(p[i]);
}

void merge(int i,int j){
	i=find(i);
	j=find(j);
	if(i==j) return;
	p[i]=j;
}

int m,n;
int main(){
	while(1){
		scanf("%d %d",&m,&n);
		if(m+n==0) break;
		for(int i=0;i<m;i++)
			p[i]=i;
		long long sum=0;
		long long ans=0;
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
			sum+=e[i].w;
		}
		sort(e,e+n);
		for(int i=0;i<n;i++){
			int a=e[i].u;
			int b=e[i].v;
			//이미 두점이 연결되어있으면
			if(find(a)==find(b)) continue;
			else{
				ans+=e[i].w;
				merge(a,b);
			}
		}
		cout<<sum-ans<<endl;
	}
	return 0;
}