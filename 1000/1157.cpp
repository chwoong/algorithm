#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>

using namespace std;

int alphabet[26]={0,};
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'A'<26) alphabet[s[i]-'A']++;
		else alphabet[s[i]-'a']++;
	}
	int tmp=-1;
	int j=0,k=1;
	for(int i=0;i<26;i++){
		int t=alphabet[i];
		if(t==tmp && t>0) { k=0;}
		else if(t>tmp && t>0){
			tmp=t;
			j=i;
			k=1;
		}
	}
	if(k) printf("%c",'A'+j);
	else cout<<'?';
	return 0;
}