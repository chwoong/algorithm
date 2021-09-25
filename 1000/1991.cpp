#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N;
class Tree{
	public:
	int num;
	vector<int>p;
	vector<int>lc,rc;
	Tree(int n){
		num=n;
		p.resize(n,-1);
		lc.resize(n,-1);
		rc.resize(n,-1);
	}
	void settree(char a,char b,char c){
		if(b!='.') {p[b-'A']=a-'A'; lc[a-'A']=b-'A';}
		else {lc[a-'A']=-1;}
		if(c!='.') {p[c-'A']=a-'A'; rc[a-'A']=c-'A';}
		else {rc[a-'A']=-1;}
		
	}
	void preorder(int root){
		printf("%c",root+'A');
		if(lc[root]!=-1) preorder(lc[root]); 
		if(rc[root]!=-1) preorder(rc[root]);
	}
	void inorder(int root){
		if(lc[root]!=-1) inorder(lc[root]); 
		printf("%c",root+'A');
		if(rc[root]!=-1) inorder(rc[root]);
	}
	void postorder(int root){
		if(lc[root]!=-1) postorder(lc[root]); 
		if(rc[root]!=-1) postorder(rc[root]);
		printf("%c",root+'A');
	}
};

int main(){
	cin >> N;
	Tree t(N);
	char a,b,c;
	for(int i=0;i<N;i++){
		cin >>a>>b>>c;
		t.settree(a,b,c);
	}
	t.preorder(0);
	cout<<'\n';
	t.inorder(0);
	cout<<'\n';
	t.postorder(0);
	return 0;
}