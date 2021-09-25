#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>
#include<cmath>

using namespace std;

int n,m;
int p[1000001];

int find(int i){
	if(p[i]==-1) return i;
	p[i]=find(p[i]);
	return p[i];
}

void merge(int a, int b){
	int f1=find(a);
	int f2=find(b);
	if(f1==f2) return;
	p[f2]=f1;
}

int main(){
	cin>>n>>m;
	memset(p,-1,sizeof(p));
	for(int i=0;i<m;i++){
		int k,a,b;
		scanf("%d %d %d",&k,&a,&b);
		if(k==1) find(a)==find(b) ? printf("YES\n") : printf("NO\n");
		if(k==0) merge(a,b);
	}
	return 0;
}