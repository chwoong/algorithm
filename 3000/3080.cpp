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

/*풀이 출처: https://github.com/kks227/BOJ/blob/master/3000/3080.cpp */
#define MOD 1000000007
const int N=26;

struct Trie;
typedef pair<int,Trie*> t;
struct Trie{
	vector<t> child;
	bool terminal=false;
	void insert(const char* key){
		if(*key=='\0') terminal=true;
		else{
			for(auto& ele:child){
				if(ele.first==*key-'A'){
					ele.second->insert(key+1);
					return;
				}
			}
			child.push_back(t(*key-'A',new Trie));
			child.back().second->insert(key+1);
		}
	}
	long long solve(){
		long long ret=1;
		long long num=1;
		if(terminal){
			for(auto& ele:child){
				ret=(ret*(++num))%MOD;
				ret=(ret*ele.second->solve())%MOD;
			}
		}else{
			for(auto& ele:child){
				ret=(ret*(num++))%MOD;
				ret=(ret*ele.second->solve())%MOD;
			}
		}
		return ret;
	}
};

int main(){
	int n;
	cin>>n;
	Trie *root=new Trie;
	for(int i=0;i<n;i++){
		char s[3010];
		scanf("%s",s);
		root->insert(s);
	}
	printf("%lld",(root->solve())%MOD);
	delete root;
	return 0;
}