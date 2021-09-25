#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N;
int del;
int leaf=0;
class Tree{
	public:
	int num;
	vector<vector<int>>adj;
	Tree(int i){
		num=i;
		adj.resize(N);
	}
	void setTree(int p,int c){
		adj[p].push_back(c);
	}
	void dfs(int curr){
		if(curr==del) return;
		if(adj[curr].size()==0) {leaf++; return;}
		if(adj[curr].size()==1 && adj[curr][0]==del)  {leaf++; return;}
		for(int i:adj[curr]){
			dfs(i);
		}
	}
};

int main(){
	int root;
	cin>>N;
	Tree t(N);
	int parent;
	for(int i=0;i<N;i++){
		cin >>parent;
		if(parent!=-1) t.setTree(parent,i);
		else root=i;
	}
	cin>>del;
	t.dfs(root);
	cout<<leaf;
	return 0;
}