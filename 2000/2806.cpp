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

int N;
string s;
//첫 i개가 A가 되기 위한 최소 횟수
int a[1000001];
//첫 i개가 B가 되기 위한 최소 횟수
int b[1000001];

int solve_a(int i);
int solve_b(int i);

int main(){
	cin>>N;
	cin>>s;
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	if(s[0]=='A') {a[0]=0;b[0]=1;}
	else {a[0]=1;b[0]=0;}
	
	cout<<solve_a(N);
	return 0;
}

int solve_a(int i){
	int&ret =a[i];
	if(ret!=-1) return ret;
	if(s[i-1]=='A') ret=solve_a(i-1);
	else ret=min(1+solve_a(i-1),1+solve_b(i-1));
	return ret;
}

int solve_b(int i){
	int&ret=b[i];
	if(ret!=-1) return ret;
	if(s[i-1]=='B') ret=solve_b(i-1);
	else ret=min(1+solve_a(i-1),1+solve_b(i-1));
	return ret;
}