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

#define MAX 1001
int n,m;
int a[MAX],b[MAX];
vector<int> adj[MAX];
bool visited[MAX];
int cnt;


//a�� ���� i���� b�� ��Ī���� ���� �������� ���� ��� ã��
bool dfs(int i){
	if(visited[i]) return 0;
	visited[i]=true;
	for(int j:adj[i]){
		//���� ��Ī�� �ȵǾ��ְų� ��Ī�� �Ǿ� �־ b[j]���� �����ϴ� ���� ��ΰ� ������
		if(b[j]==-1 || dfs(b[j])){
			a[i]=j;
			b[j]=i;
			return 1;
		}
	}
	return 0;
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		while(x--){
			int c;
			scanf("%d",&c);
			adj[i].push_back(c);
		}
	}
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	for(int i=0;i<n;i++){
		memset(visited,0,sizeof(visited));
		if(dfs(i)) cnt++;
	}
	cout<<cnt;
	return 0;
}