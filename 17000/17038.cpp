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
using namespace std;

int n,m;
vector<int> s[101010];
vector<int> d[101010];
bool visited[101010];
int arr[101010];
int ans=0;
//col´Â 1¶Ç´Â2
long long dfs(int i,int col){
	visited[i]=true;
	arr[i]=col;
	long long tmp=1;
	for(int next:s[i]){
		if(visited[next] && arr[next]==3-col) tmp=0;
		if(!visited[next]) tmp=min(tmp,dfs(next,col));
	}
	for(int next:d[i]){
		if(visited[next] && arr[next]==col) tmp=0;
		if(!visited[next]) tmp=min(tmp,dfs(next,3-col));
	}
	return tmp;
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		char q[3];
		int x,y;
		scanf("%s %d %d",q,&x,&y);
		if(q[0]=='S'){
			s[x].push_back(y);
			s[y].push_back(x);
		}else{
			d[x].push_back(y);
			d[y].push_back(x);
		}
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			int x=dfs(i,1);
			if(x==0) {puts("0");return 0;}
			else ans++;
		}
	}
	printf("1");
	for(int i=0;i<ans;i++){
		printf("0");
	}
	return 0;
}