#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<cmath>
using namespace std;

int n,m,x;
vector<int> adj[100001];
vector<int> rev[100001];
bool visited1[100001];
bool visited2[100001];
int dfs(int i){
	int ret=1;
	visited1[i]=true;
	for(int ele:adj[i]){
		if(!visited1[ele]) ret+=dfs(ele);
	}
	return ret;
}
int revdfs(int i){
	int ret=1;
	visited2[i]=true;
	for(int ele:rev[i]){
		if(!visited2[ele]) ret+=revdfs(ele);
	}
	return ret;
}
int main(){
	cin>>n>>m>>x;
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		rev[b].push_back(a);
	}
	int s=dfs(x);
	int s2=revdfs(x);
	s--; s2--;
	//s는 x뒤에 있는 사람 수
	//s2는 x앞에 있는 사람 수
	cout<<s2+1<<' '<<n-s;
	return 0;
}