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

int n;
string x1,x2;
string s;
int main(){
	cin>>n;
	cin>>s;
	x1="";
	x2="";
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='*') break;
		x1+=s[i];
	}
	for(int i=len-1;i>=0;i--){
		if(s[i]=='*') break;
		x2+=s[i];
	}
	int a=x1.size();
	int b=x2.size();
	for(int i=0;i<n;i++){
		cin>>s;
		int len=s.size();
		if(len<a+b) {puts("NE"); continue;}
		bool tmp=true;
		for(int j=0;j<a;j++){
			if(s[j]!=x1[j]) tmp=false;
		}
		reverse(s.begin(),s.end());
		for(int j=0;j<b;j++){
			if(s[j]!=x2[j]) tmp=false;
		}
		if(tmp) puts("DA");
		else puts("NE");
	}
	return 0;
}