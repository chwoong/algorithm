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

//jason���� Ǯ�̸� ���� ��������

#define INF 1000000000
int n,q,cnt(1);
vector<int> adj[200010];
int p[200010];
//dfs�� �ؼ� ��Ʈ ���� ���ο� index�� ����
//ind�� outd�� parent, depth ��� ���ο� index����
int ind[200010];
int outd[200010];
//parent[i][k]: i�� 2^k��° �θ� ���
int parent[200010][22];
//���ο� �ε��������� ���� ����
int depth[200010];

//segnent tree
int lazy[800010];
int seg[800010];

void getind(int here){
	ind[here]=cnt++;
	for(int next:adj[here]){
		getind(next);
	}
	outd[here]=cnt;
}

void dfs(int here){
	for(int next:adj[here]){
		parent[ind[next]][0]=ind[here];
		depth[ind[next]]=depth[ind[here]]+1;
		dfs(next);
	}
}
//lazy propagation segment tree
//1~n index���� ���� [l,r]���� �ö� �� �ִ� �ִ� ����
void propagate(int node,int nodel,int noder){
	if(lazy[node]!=0){
		seg[node]=max(seg[node],lazy[node]);
		//leaf�� �ƴϸ�
		if(nodel!=noder){
			lazy[node*2]=max(lazy[node*2],lazy[node]);
			lazy[node*2+1]=max(lazy[node*2+1],lazy[node]);
		}
		lazy[node]=0;
	}
}
void update(int node,int nodel,int noder,int l,int r,int val){
	propagate(node,nodel,noder);
	if(nodel>r || noder<l) return;
	else if(l<=nodel && noder<=r){
		lazy[node]=max(lazy[node],val);
		propagate(node,nodel,noder);
		return;
	}
	int mid=(nodel+noder)/2;
	update(node*2,nodel,mid,l,r,val);
	update(node*2+1,mid+1,noder,l,r,val);
	seg[node]=max(seg[node*2],seg[node*2+1]);
}
int query(int node,int nodel,int noder,int l,int r){
	propagate(node,nodel,noder);
	if(nodel>r || noder<l) return -1;
	if(l<=nodel && noder<=r) return seg[node];
	int mid=(nodel+noder)/2;
	return max( query(node*2,nodel,mid,l,r) , query(node*2+1,mid+1,noder,l,r) );
}

//i�� j�� ��η� ����Ǿ� �ִ°�?
//lca�� i�� j���� �� �� �ִ� �ִ� �θ� ����ϰ� ���� �������� ��
bool ispath(int i,int j){
	//�θ�� ������ �󸶳� ���� �ö󰡾� �ϴ°�
	int up_i=depth[i]-query(1,1,n,i,i);
	int up_j=depth[j]-query(1,1,n,j,j);
	for(int x=20;x>=0;x--){
		if((up_i & (1<<x)) && parent[i][x]) i=parent[i][x];
	}
	for(int x=20;x>=0;x--){
		if((up_j & (1<<x)) && parent[j][x]) j=parent[j][x];
	}
	return i==j;
}

int main(){
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		int x;
		scanf("%d",&x);
		p[i]=x;
		adj[x].push_back(i);
	}
	//��Ʈ�� �׻� 1�̴�.
	getind(1);
	dfs(1);
	//sparse table�� lca�� ����ϱ� ���� parent������ bottom up���� �̸� ��� ����
	//2^20>200000
	//parent�� �� �̻� ������ �θ� ���� 0���� �д�.
	for(int i=1;i<=20;i++){
		for(int j=1;j<=n;j++){
			parent[j][i]=parent[parent[j][i-1]][i-1];
		}
	}
	while(q--){
		int u,v,d;
		scanf("%d %d %d",&u,&v,&d);
		if(d){
			if(ispath(ind[u],ind[v])){ 
				puts("YES");
				update(1,1,n,ind[u],outd[u]-1,depth[ind[u]]);
			}else{
				puts("NO");
				update(1,1,n,ind[v],outd[v]-1,depth[ind[v]]);
			}
		}else{
			if(ispath(ind[u],ind[v])) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}