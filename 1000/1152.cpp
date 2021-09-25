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
#include<cmath>

using namespace std;

string s;
int main(){
	getline(cin,s);
	int num=0;
	char prev=s[0];
	if(prev!=' ') num++;
	for(int i=1;i<s.size();i++){
		if(prev==' ' && s[i]!=' ') num++;
		prev=s[i];
	}
	cout<<num;
	return 0;
}