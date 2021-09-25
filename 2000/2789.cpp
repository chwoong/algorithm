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

string s;
bool arr[26];
int main(){
	cin>>s;
	string s1="CAMBRIDGE";
	int len1=s1.size();
	for(int i=0;i<len1;i++){
		arr[s1[i]-'A']=true;
	}
	int len=s.size();
	int cnt=0;
	for(int i=0;i<len;i++){
		if(!arr[s[i]-'A']) cout<<s[i];
	}
	return 0;
}