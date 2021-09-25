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
using namespace std;

int N;

int main(){
	cin>>N;
	string s;
	cin>>s;
	int len=s.size();
	int seat=1;
	int lnum=0;
	for(int i=0;i<len;i++){
		if(s[i]=='S') seat++;
		else if(lnum==0) lnum=1;
		else {seat++; lnum=0;}
	}
	cout<<min(N,seat);
	return 0;
}