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
using namespace std;

typedef pair<int,int> P;
string word,key;
stack<P> s;
int cnt=0;
bool isexplode[1000000];
int main(){
	cin>>word;
	cin>>key;
	int len=word.size();
	int x=key.size();
	for(int i=0;i<len;i++){
		if(word[i]==key[0]){
			s.push(P(0,i));
			cnt=1;
			if(cnt==x){
				int tmp=x;
				while(tmp--){
					P here=s.top();
					s.pop();
					isexplode[here.second]=true;
				}
				cnt=0;
			}
		}else if(word[i]==key[cnt]){
			s.push(P(cnt,i));
			cnt++;
			if(cnt==x){
				int tmp=x;
				while(tmp--){
					P here=s.top();
					s.pop();
					isexplode[here.second]=true;
				}
				if(!s.empty()){
					P now=s.top();
					cnt=now.first+1;
				}else cnt=0;
			}
		}else if(word[i]!=key[cnt]){
			stack<P> em;
			swap(em,s);
			cnt=0;
		}
	}
	bool a=true;
	for(int i=0;i<len;i++){
		if(!isexplode[i]) {a=false; printf("%c",word[i]);}
	}
	if(a) puts("FRULA");
	return 0;
}