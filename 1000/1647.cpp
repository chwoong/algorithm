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
}e[1000000];
bool operator<(edge a,edge b){return a.w<b.w;}

int p[100001];

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
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e,e+m);
	int ans=0;
	int cnt=0;
	for(int i=0;i<m;i++){
		if(find(e[i].u)==find(e[i].v)) continue;
		ans+=e[i].w;
		merge(e[i].u,e[i].v);
		cnt++;
		if(cnt==n-2) break;
	}
	cout<<ans;
	return 0;
}