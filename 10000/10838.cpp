#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<set>
#include<stdlib.h>
#include<string>
#include<utility>
#include<stack>
using namespace std;
//부모노드
int p[100000];
//부모로 향하는 edge 색깔
int col[100000];
int N,K;
int x=0;
int cnt[100000];
//a와 b의 lca를 찾자
int find(int a,int b){
	x++;
	int numa=0;
	while(a!=-1 && numa<=1000){
		cnt[a]=x;
		a=p[a];
		numa++;
	}
	while(cnt[b]!=x){
		b=p[b];
	}
	return b;
}
int main(){
	cin>>N>>K;
	p[0]=-1;
	while(K--){
		int r,a,b,c;
		scanf("%d",&r);
		if(r==1){
			scanf("%d %d %d",&a,&b,&c);
			int par=find(a,b);
			while(a!=par){
				col[a]=c;
				a=p[a];
			}
			while(b!=par){
				col[b]=c;
				b=p[b];
			}
		}else if(r==2){
			scanf("%d %d",&a,&b);
			p[a]=b;
		}else{
			scanf("%d %d",&a,&b);
			int par=find(a,b);
			set<int> s;
			while(a!=par){
				s.insert(col[a]);
				a=p[a];
			}
			while(b!=par){
				s.insert(col[b]);
				b=p[b];
			}
			printf("%d\n",(int)s.size());
		}
	}
	return 0;
}