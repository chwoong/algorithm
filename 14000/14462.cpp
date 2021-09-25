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

vector<int> adj[1000];
vector<int> bdj[1000];
int dp[1000][1000];
int arr[1000];
int brr[1000];
int n;

int solve(int i,int j){
	if(i==n || j==n) return 0;
	int& ret=dp[i][j];
	if(ret!=-1) return ret;
	ret=0;
	for(int next:adj[i]){
		if(next>=j) ret=max(ret,1+solve(i+1,next+1));
	}
	for(int next:bdj[j]){
		if(next>=i) ret=max(ret,1+solve(next+1,j+1));
	}
	ret=max(ret,solve(i+1,j+1));
	return ret;
}

int main(){
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	for(int i=0;i<n;i++)
		scanf("%d",brr+i);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(abs(arr[i]-brr[j])<=4){
				adj[i].push_back(j);
				bdj[j].push_back(i);
			}
		}
	}
	cout<<solve(0,0);
	return 0;
}