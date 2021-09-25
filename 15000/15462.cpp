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

int n;
int arr[100001];
bool visited[100001];
bool finished[100001];
int cycle;

void dfs(int here){
	visited[here]=true;
	int next=arr[here];
	//cycle 시작(next~here)
	//이 때 next와 here이 같을 수도 있다.
	if(visited[next] && !finished[next]){
		int i=next;
		cycle++;
		for(;i!=here;i=arr[i]){
			cycle++;
		}
	}
	else if(!visited[next]) dfs(next);
	finished[here]=true;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]) dfs(i);
	}
	cout<<cycle;
	return 0;
}