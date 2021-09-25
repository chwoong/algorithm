#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int n;
vector<string> v;
vector<int> adj[26];
int indeg[26];
bool alpha[26];
int ans[26];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		v.push_back(s);
		int len=s.size();
		for(int j=0;j<len;j++) alpha[s[j]-'a']=true;
	}
	int all=0;
	for(int i=0;i<26;i++)
		if(alpha[i]) all++;
	for(int i=0;i<n-1;i++){
		string s=v[i];
		string s1=v[i+1];
		int len=s.size();
		int len1=s1.size();
		int x=min(len,len1);
		bool a=true;
		for(int i=0;i<x;i++){
			if(s[i]==s1[i]) continue;
			else {
				a=false;
				adj[s[i]-'a'].push_back(s1[i]-'a');
				indeg[s1[i]-'a']++;
				break;
			}
		}
		if(a && len>len1) {puts("!"); return 0;}
	}
	queue<int> q;
	for(int i=0;i<26;i++){
		if(alpha[i] && indeg[i]==0) q.push(i);
	}
	int tmp=0;
	for(int i=0;i<all;i++){
		if(q.empty()) {tmp=2; break;}
		else if(q.size()>=2) tmp=1;
		int x=q.front();
		q.pop();
		ans[i]=x;
		for(int next:adj[x]){
			if(--indeg[next]==0) q.push(next);
		}
	}
	if(tmp==0){
		for(int i=0;i<all;i++){
			printf("%c",ans[i]+'a');
		}
	}else if(tmp==1) puts("?");
	else puts("!");
	return 0;
}