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

typedef pair<int,int> P;

int t;
int N,M;
int cnt;
int col;
vector<int> adj[100001];
int low[100001];
int discovered[100001];
bool visited[100001];
//���� ���� ���� bcc�� ���� ���� ����
set<int> bcc[100001];
//�信 ���ԵǴ°�?
bool ans[100001];
bool v[100001];
bool val[100001];
bool ret;
void dfs(int i,int prev){
	discovered[i]=low[i]=++cnt;
	for(int next:adj[i]){
		if(next==prev) continue;
		if(discovered[next]==0){
			dfs(next,i);
			low[i]=min(low[next],low[i]);
		}
		else low[i]=min(low[i],discovered[next]);
	}
}

void color(int i,int c){
	if(c>0) bcc[c].insert(i);
	visited[i]=true;
	for(int next:adj[i]){
		if(visited[next]) continue;
		if(discovered[i]<=low[next]){
			bcc[++col].insert(i);
			color(next,col);
		}else color(next,c);
	}
}

void solve(int i,int s,bool c){
	v[i]=true;
	val[i]=c;
	for(int next:adj[i]){
		if(bcc[s].count(next)){
			if(!v[next]) solve(next,s,!c);
			else{
				//�̺б׷����� �ƴ�
				if(val[i]==val[next]) ret=false;
			}
		}
	}
}

int main(){
	cin>>t;
	while(t--){
		cin>>N>>M;
		for(int i=0;i<M;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(int i=1;i<=N;i++)
			if(discovered[i]==0) dfs(i,0);
		for(int i=1;i<=N;i++){
			col=0;
			if(!visited[i]) color(i,0);
			for(int j=1;j<=col;j++){
				//bcc[j]�� ���Ե� ������ �ȿ� Ȧ�� ����Ŭ�� �ִ��� Ȯ������.
				//�̺б׷����� �ƴϾ�� Ȧ�� ����Ŭ�� �����Ѵ�
				ret=true;
				solve(*bcc[j].begin(),j,0);
				//Ȧ�� ����Ŭ ����
				if(!ret){
					for(int ele:bcc[j]){
						ans[ele]=true;
					}
				}
				for(int ele:bcc[j]){
					v[ele]=val[ele]=0;
				}
			}
			
			for(int j=1;j<=col;j++)
				bcc[j].clear();
		}
		int x=0;
		for(int i=1;i<=N;i++)
			if(ans[i]) x++;
		cout<<x<<endl;
		//�ʱ�ȭ ������
		for(int i=1;i<=N;i++){
			adj[i].clear();
			bcc[i].clear();
			low[i]=0;
			discovered[i]=0;
			visited[i]=false;
			ans[i]=false;
		}
	}
	
	
	return 0;
}