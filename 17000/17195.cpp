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
int m[1000][1000];
int cnt=0;
int sum(int i,int j){
	return (m[i][j]+m[(i+1)%n][j]+m[i][(j+1)%n]+m[(i+1)%n][(j+1)%n])%2;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<n;j++){
			if(s[j]=='R') m[i][j]=1;
			else m[i][j]=0;
		}
	}
	if(n==2) {
		if(sum(0,0)==1) printf("1 1");
		else puts("-1");
		return 0;
	}
	int x,y;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(sum(i,j)==0) continue;
			//i,j로 시작하는 2*2정사각형 중에 범인이 있다.
			if(sum((i+1)%n,(j+1)%n)==1) {x=(i+1)%n;y=(j+1)%n;}
			else if(sum(i,(j+1)%n)==1) {x=i;y=(j+1)%n;}
			else if(sum((i+1)%n,j)==1) {x=(i+1)%n;y=j;}
			else {x=i; y=j;}
			cnt++;
		}
	}
	if(cnt==4) printf("%d %d",x+1,y+1);
	else puts("-1");
	return 0;
}