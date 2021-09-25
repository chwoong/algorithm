#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

int n;
int val[10001];
vector<int> adj[10001];
int msize=0;
/*1번이 루트 i번을 포함하냐 안하냐의 탐색에서의 최댓값*/
int dp[10001][2];

int sum=0;

int dfs(int curr,int before){
	/*curr 선택*/
	int &ret1 = dp[curr][1];
	if(ret1 == -1){
		ret1=val[curr];
		for(int next:adj[curr]){
			if(next!=before){
				for(int twonext:adj[next]){
					if(twonext!=curr) ret1+=dfs(twonext,next);
				}
			}
		}
	}
	/*curr 선택 안함*/
	int &ret2 = dp[curr][0];	
	if(ret2==-1){
		ret2=0;
		for(int next: adj[curr]){
			if(next != before) ret2+=dfs(next,curr);
		}
	}
	return max(ret1,ret2);
}
void findpath(int curr,int before,vector<int>&path){
	/*포함하는게 이득*/
	if(dp[curr][1]>=dp[curr][0]){
		path.push_back(curr);
		for(int next:adj[curr]){
			if(next!=before){
				for(int twonext:adj[next]){
					if(twonext!=curr) findpath(twonext,next,path);
				}
			}
		}
	}
	/*안포함하는게 이득*/
	else{
		for(int next: adj[curr]){
			if(next != before) findpath(next,curr,path);
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>val[i];
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	memset(dp,-1,sizeof(dp));
	msize=dfs(1,0);
	cout<<msize<<endl;
	vector<int> p;
	findpath(1,0,p);
	sort(p.begin(),p.end());
	for(int ele:p)
		cout<<ele<<" ";
	return 0;
}