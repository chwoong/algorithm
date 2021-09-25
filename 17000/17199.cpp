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

vector<int> adj[100];
bool visited[100];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[b-1].push_back(a-1);
	}
	for(int i=0;i<n;i++){
		memset(visited,false,sizeof(visited));
		queue<int> q;
		q.push(i);
		visited[i]=true;
		while(!q.empty()){
			int here=q.front();
			q.pop();
			for(int next:adj[here]){
				if(!visited[next]){
					visited[next]=true;
					q.push(next);
				}
			}
		}
		int x=0;
		for(int i=0;i<n;i++){
			x+=visited[i];
		}
		if(x==n) {cout<<i+1;return 0;}
	}
	cout<<-1;
	return 0;
}