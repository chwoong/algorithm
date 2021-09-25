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
#include<math.h>
using namespace std;

typedef pair<double,double> P;
P point[100];
struct edge{
	int u,v;
	double w;	
}e[10000];
bool operator<(edge a,edge b){return a.w<b.w;}

int p[100];

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

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		p[i]=i;
	for(int i=0;i<n;i++){
		scanf("%lf %lf",&point[i].first,&point[i].second);
	}
	int cnt=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			e[cnt].u=i;
			e[cnt].v=j;
			e[cnt].w=sqrt((point[i].first-point[j].first)*(point[i].first-point[j].first)+(point[i].second-point[j].second)*(point[i].second-point[j].second));
			cnt++;
		}
	}
	double ans=0;
	sort(e,e+cnt);
	for(int i=0;i<cnt;i++){
		if(find(e[i].u)==find(e[i].v)) continue;
		ans+=e[i].w;
		merge(e[i].u,e[i].v);
	}
	cout<<ans;
	return 0;
}