#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N;
/* subtree의 크기, root포함 */
int size[10001]={0,};
/* 각 노드의 x축 위치 */
int pos[10001]={0,};
/* 각 레벨당 가장 왼쪽과 가장 오른쪽 위치 */
int lefts[10001];
int rights[10001];
int depth=1;
int root;

class Tree{
	public:
	int num;
	vector<int> lc,rc;
	Tree(int n){
		num=n;
		lc.reserve(num+1);
		rc.reserve(num+1);
	}
	void setTree(int node,int ch1,int ch2){
		lc[node]=ch1;
		rc[node]=ch2;
	}
	/* node i의 트리 크기를 반환 */
	int getsize(int i){
		int& ret = size[i];
		if(ret!=0) return ret;
		if(lc[i]==-1 && rc[i]==-1) ret=1;
		else if(lc[i]==-1 && rc[i]!=-1) ret=1+getsize(rc[i]);
		else if(lc[i]!=-1 && rc[i]==-1) ret=1+getsize(lc[i]);
		else ret = 1+getsize(lc[i]) + getsize(rc[i]);
		return ret;
	}
	/* root의 위치 설정 */
	void setone(int root){
		if(lc[root]==-1) pos[root]=1;
		else pos[root]=size[lc[root]]+1;
	}
	/*bfs하면서 각 node의 위치를 저장함*/
	void bfs(){
		queue<int> q;
		q.push(root);
		lefts[1]=pos[root];
		rights[1]=pos[root];
		while(!q.empty()){
			lefts[depth]=pos[q.front()];
			rights[depth]=pos[q.back()];
			int len=q.size();
			depth++;
			for(int i=0;i<len;i++){
				int here=q.front();
				q.pop();
				if(lc[here]!=-1){
					if(rc[lc[here]]==-1) pos[lc[here]]=pos[here]-1;
					else pos[lc[here]]=pos[here]-size[rc[lc[here]]]-1;
					q.push(lc[here]);
				}
				if(rc[here]!=-1){
					if(lc[rc[here]]==-1) pos[rc[here]]=pos[here]+1;
					else pos[rc[here]]=pos[here]+size[lc[rc[here]]]+1;
					q.push(rc[here]);
				}
			}
		}
	}
};


int main(){
	int r[10001]={0,};
	scanf("%d\n",&N);
	Tree t(N);
	int node, ch1, ch2;
	for(int i=0;i<N;i++){
		scanf("%d %d %d\n",&node,&ch1,&ch2);
		t.setTree(node,ch1,ch2);
		r[ch1]=1;
		r[ch2]=1;
	}
	for(int i=1;i<=N;i++){
		if(r[i]==0) {root=i; break;}
	}
	/* 각 노드의 서브트리 크기 저장 */
	t.getsize(root);
	/* root의 위치*/
	t.setone(root);
	/* bfs하면서 각 노드 위치 저장 */
	t.bfs();

	int m=1;
	int s=1;
	for(int i=1;i<depth;i++){
		int tmp=m;
		m=max(rights[i]-lefts[i]+1,m);
		if(tmp<m) {s=i;}
	}
	cout<<s<<" "<<m;

return 0;
}