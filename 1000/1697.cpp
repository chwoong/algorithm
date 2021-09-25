#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

int N, K;

bool visited[100001];
int bfs(){
	int depth=0;
	queue<int> q;
	q.push(N);
	visited[N]=true;
	if(N==K) return 0;
	while(1){
		depth++;
		int len=q.size();
		for(int i=0;i<len;i++){
			int x=q.front();
			q.pop();
			if(x+1==K || x-1==K || 2*x==K) return depth;
			if(x<100000 && visited[x+1]==false) {visited[x+1]=true; q.push(x+1);}
			if(x>0 && visited[x-1]==false) {visited[x-1]=true;q.push(x-1);}
			if(x<=50000 && visited[2*x]==false) {visited[2*x]=true;q.push(2*x);}
		}
	}
}

int main(){
	cin>>N>>K;
	memset(visited,false,sizeof(visited));
	cout<< bfs();
	return 0;
}