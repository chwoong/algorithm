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

const int N=10;

struct Trie{
	Trie* child[N];
	bool terminal;
	Trie():terminal(false){
		memset(child,0,sizeof(child));
	}
	~Trie(){
		for(int i=0;i<N;i++){
			if(child[i]) delete child[i];
		}
	}
	void insert(const char*key){
		if(*key=='\0') terminal=true;
		else{
			int next=*key-'0';
			if(child[next]==NULL){
				child[next]=new Trie();
			}
			child[next]->insert(key+1);
		}
	}
	bool consistent(){
		if(terminal){
			for(int i=0;i<N;i++){
				if(child[i]) return false;
			}
		}
		for(int i=0;i<N;i++){
			if(child[i] && !child[i]->consistent()) return false;
		}
		return true;
	}
};

int t;
int main(){
	cin>>t;
	while(t--){
		int n;
		scanf("%d",&n);
		Trie* root=new Trie;	
		for(int i=0;i<n;i++){
			char s[15];
			scanf("%s",s);
			root->insert(s);
		}
		printf("%s\n",root->consistent()?"YES":"NO");
		delete root;
	}
	
	return 0;
}