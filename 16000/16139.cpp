#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
using namespace std;

char c[200010];
//string c;
int prefix[200010][26];
int q;
int main(){
	scanf("%s",c);
	scanf("%d",&q);
	int i=0;
	while(c[i]!='\0'){
		for(int j=0;j<26;j++){
			prefix[i+1][j]=prefix[i][j];
		}
		prefix[i+1][c[i]-'a']+=1;
		i++;
	}
	char x;
	int l,r;
	while(q--){
		cin>>x>>l>>r;
		printf("%d\n",prefix[r+1][x-'a']-prefix[l][x-'a']);
	}
	return 0;
}