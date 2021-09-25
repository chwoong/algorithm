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

double x[1000];
double y[1000];
double r[1000];

struct edge{
	int u,v;
	double w;
}e[1000000];
bool operator<(edge a,edge b){return a.w<b.w;}

int p[1010];

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
	int t;
	cin>>t;
	while(t--){
		int w0,n;
		//정점 번호 n,n+1이 벽 양쪽을 의미
		//1~(n-1)까지는 센서 정점을 의미
		cin>>w0>>n;
		for(int i=0;i<=n+1;i++)
			p[i]=i;
		for(int i=0;i<n;i++){
			scanf("%lf %lf %lf",x+i,y+i,r+i);
		}
		int cnt=0;
		//센서간의 거리
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				double d=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				e[cnt].u=i;
				e[cnt].v=j;
				e[cnt].w=d-r[i]-r[j];
				cnt++;
			}
		}
		//센서와 왼쪽 벽간의 거리
		for(int i=0;i<n;i++){
			e[cnt].u=i;
			e[cnt].v=n;
			e[cnt].w=x[i]-r[i];
			cnt++;
		}
		//센서와 오른쪽 벽간의 거리
		for(int i=0;i<n;i++){
			e[cnt].u=i;
			e[cnt].v=n+1;
			e[cnt].w=(w0-x[i])-r[i];
			cnt++;
		}
		//벽 간의 거리
		e[cnt].u=n;
		e[cnt].v=n+1;
		e[cnt].w=w0;
		cnt++;
		sort(e,e+cnt);
		for(int i=0;i<cnt;i++){
			int a=e[i].u;
			int b=e[i].v;
			if(find(a)==find(b)) continue;
			merge(a,b);
			if(find(n)==find(n+1)){
				printf("%f\n",max(e[i].w/2.0,0.0));
				break;
			}
		}
	}
	return 0;
}