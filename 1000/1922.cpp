#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;

//1922. 크루스칼의 최소 스패닝 알고리즘


struct Edge{
	int u,v,w;
	Edge(){}
	Edge(int i,int j,int k):u(i),v(j),w(k){}
	bool operator<(const Edge e) {return w<e.w;}
}e[100000];

int p[1001];

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

int n,m;
int ans;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		e[i]=Edge(a,b,c);
	}
	sort(e,e+m);
	for(int i=0;i<m;i++){
		int x=e[i].u;
		int y=e[i].v;
		if(find(x)==find(y)) continue;
		else{
			merge(x,y);
			ans+=e[i].w;
		}
	}
	cout<<ans;
	return 0;
}