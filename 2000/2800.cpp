#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<set>
#include<stdlib.h>
#include<string>
#include<utility>
#include<stack>
using namespace std;

stack<int>st;
set<string>v;
int k=0;
int p[300];
int brac=0;
int main(){
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='(') st.push(i);
		if(s[i]==')'){
			p[i]=k;
			p[st.top()]=k;
			st.pop();
			brac+=1<<k;
			k++;
		}
	}
	brac--;
	while(brac!=-1){
		string s1="";
		for(int i=0;i<len;i++){
			if(s[i]=='(' || s[i]==')'){
				if(brac&(1<<p[i])) s1+=s[i];
			}
			else s1+=s[i];
		}
		v.insert(s1);
		brac--;
	}
	for(set<string>::iterator it=v.begin();it!=v.end();it++){
		cout<<*it<<'\n';
	}
}