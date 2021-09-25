#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
using namespace std;

int n,m;
long long k;
int arr[10001];
int p[10001];
bool visited[10001];
int find(int i){
	if(p[i]<0) return i;
	return p[i]=find(p[i]);	
}

void merge(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b) return;
	p[b]=max(p[a],p[b]);
	p[a]=b;
}

int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		p[i]=-x;
	}
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		merge(a,b);
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(visited[find(i)]==false){
			sum+=p[find(i)];
			visited[find(i)]=true;
		}
	}
	if(-sum <=k) cout<<-sum;
	else cout<<"Oh no";
	return 0;
}