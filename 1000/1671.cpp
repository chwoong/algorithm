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
#include<time.h>
using namespace std;

int si[50];//ũ��
int sp[50];//���ǵ�
int in[50];//����

vector<int> adj[500];
int a[500];
int b[500];
bool visited[500];

bool dfs(int i){
	if(visited[i]) return 0;
	visited[i]=true;
	for(int j:adj[i]){
		if(b[j]==-1 || dfs(b[j])){
			a[i]=j;
			b[j]=i;
			return 1;
		}
	}
	return 0;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %d %d",si+i,sp+i,in+i);
	}
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) continue;
			else if(si[i]==si[j] && sp[i]==sp[j] && in[i]==in[j]){
				if(i<j){
					adj[2*i].push_back(100+j);
					adj[2*i+1].push_back(100+j);
				}
			}
			//i�� j�� ��� ���� �� �ִ�.
			else if(si[i]>=si[j] && sp[i]>=sp[j] && in[i]>=in[j]){
				//��� ���� �� �ִ� ���� A
				//��� ������ ���� B
				//A���� B�� ���� ��Ī �ִ��� ���� �ǵ�
				//A������ ������ ���� �� ���� ������ �� �� �ִ� �� ���� ��� ���� �� �ְ� ��
				adj[2*i].push_back(100+j);
				adj[2*i+1].push_back(100+j);
			}
		}
	}
	int cnt=0;
	for(int i=0;i<2*n;i++){
		memset(visited,0,sizeof(visited));
		if(dfs(i)) cnt++;
	}
	cout<<n-cnt;
	return 0;
}