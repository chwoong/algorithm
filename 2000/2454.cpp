/*
 *  author: chw0501
 *	reference: https://github.com/kks227/BOJ/blob/master/2400/2454.cpp
 *  created: 16.04.2020 10:50:38(UTC)
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,k;
vector<int> adj[300001];
/*(curr�� ����Ǿ��ִ� ��ο��� ���� �� ������ �� �ִ� ������ ����,
curr���� �����ϴ� Ʈ������ ���� �� �ִ� �ִ� ��� ����) ��ȯ*/
P dfs(int curr,int prev){
	int path=0;
	//�� ���� ���� ������ ���ε�
	//curr�� �ڽĵ� �߿� �� �ڽ��� ������ ��ο��� ���� �� ������ �� �ִ� ������ ����
	//�׷� ���߿� ���� ū �� 2��(a>=b)
	int a=0;
	int b=0;
	for(int next:adj[curr]){
		if(next!=prev){
			P x=dfs(next,curr);
			if(a<x.first){
				b=a;
				a=x.first;
			}else if(b<x.first) b=x.first;
			path+=x.second;
		}
	}
	//(k+1-a)+(k+1-b)+1<=k+1  : a+b>k+1  �̋��� curr�� �����ϰ� a,b�� ������ �� �ڽı��� �����ִ� ��θ� ����
	//�׷��� path�������� 1���� �̵溻��
	//�� ��쿡�� path�������� �ϳ��� �̵�����Ƿ� �ٷ� ���� �ι�° ���̽�ó�� ����� �͵� �����ϴ�.(���� �ֿ켱������ �̰�츦 ����)
	if(a+b>k+1) return P(0,path-1);
	//�װ� �ƴϸ� ���� ������ ���� �� �߿� ���� ���� ���� ���� ����
	if(a) return P(a-1,path);
	//�װ͵� �ƴϸ� curr�� ���� �ϳ��� ��η� ���� �������� �˾Ƽ� ���ҵ�
	return P(k,path+1); 
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout<<dfs(1,0).second;
	return 0;
}