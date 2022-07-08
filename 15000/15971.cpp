#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
using namespace std;
typedef pair<int,int> P;
//�� �κ� ���� ���
int a,b;
int N;
vector<vector<P>>adj;
bool visited[100001];
int p[100001]; //�θ� ��� ����
int pd[100001]; //�θ� ���� ���� ��� ���� ����
void bfs(){
	visited[b]=true;
	queue<int> q;
	q.push(b);
	bool tmp=true;
	while(!q.empty()&&tmp){
		int curr=q.front();
		q.pop();
		for(P ele: adj[curr]){
			if(!visited[ele.first]){
				visited[ele.first]=true;
				q.push(ele.first);
				p[ele.first]=curr;
				pd[ele.first]=ele.second;
				if(ele.first==a){tmp=false;break;}
			}
		}
	}
}

int main(){
	cin>>N>>a>>b;
	adj.resize(N+1);
	for(int i=1;i<N;i++){
		int x,y,d;
		scanf("%d %d %d",&x,&y,&d);
		adj[x].push_back(P(y,d));
		adj[y].push_back(P(x,d));
	}
	//bfs�� b���� �����ؼ� a�� ã�� ������ ��θ� �����ϸ鼭 ���̸� ������
	bfs();
	int i=a;
	int len=0;
	int max_len=0;
	while(i!=b){
		len+=pd[i];
		max_len=max(max_len,pd[i]);
		i=p[i];
	}
	cout<<len-max_len;
	return 0;
}