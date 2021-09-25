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

int x;

string change(string s,int l){
	string ret="";
	for(int i=0;i<l/2;i++){
		ret+=s[i];
		ret+=s[l-1-i];
	}
	if(l%2) ret+=s[l/2];
	return ret;
}
int main(){
	cin>>x;
	string s;
	cin>>s;
	int len=s.size();
	int period=1;
	string ret=s;
	while(1){
		ret=change(ret,len);
		if(ret==s) break;
		else period++;
	}
	string ans=s;
	int a=(period-x%period);
	for(int i=0;i<a;i++){
		ans=change(ans,len);
	}
	cout<<ans;
	return 0;
}