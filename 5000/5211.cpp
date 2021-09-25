#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int len=s.size();
	int a(0),b(0),c(0);
	bool v=true;
	for(int i=0;i<len;i++){
		if(v){
			if(s[i]=='A'||s[i]=='D'||s[i]=='E') a++;
			else if(s[i]=='C'||s[i]=='F'||s[i]=='G') b++;
			v=false;
		}
		else if(s[i]=='|') v=true;
	}
	if(s[len-1]=='A'||s[len-1]=='D'||s[len-1]=='E') c=1;
	if(a<b) puts("C-major");
	else if(a>b) puts("A-minor");
	else if(!c) puts("C-major");
	else puts("A-minor");
	return 0;
}