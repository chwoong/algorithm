#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<string.h>
using namespace std;

int N,Q;
int p[200001];

int find(int i){
	while(p[i]!=i){
		i=p[i];
	}
	return i;
}
int main(){
	cin>>N>>Q;
	for(int i=2;i<=N;i++)
		scanf("%d",p+i);
	for(int j=0;j<(N-1)+Q;j++){
		int a,b,c;
		scanf("%d",&a);
		if(a==0){scanf("%d",&b); p[b]=b;}
		if(a==1){
			scanf("%d %d",&b,&c);
			if(find(b)==find(c)) puts("YES");
			else puts("NO");
		}
	}
}