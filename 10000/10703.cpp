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
#include<cmath>
using namespace std;

int r,s;
char m[3000][3000];
char ans[3000][3000];
int main(){
	cin>>r>>s;
	for(int i=0;i<r;i++){
		string s1;
		cin>>s1;
		for(int j=0;j<s;j++){
			m[i][j]=s1[j];
			ans[i][j]='.';
		}
	}
	//유성이 몇칸까지 내려갈 수 있는가
	int ret=3000;
	for(int j=0;j<s;j++){
		int h=3000;
		int l=0;
		bool tmp=false;
		for(int i=0;i<r;i++){
			if(m[i][j]=='X') {tmp=true; l=max(l,i);}
			else if(m[i][j]=='#') h=min(h,i);
		}
		if(tmp) ret=min(ret,h-l);
	}
	ret--;
	for(int i=0;i<r;i++){
		for(int j=0;j<s;j++){
			if(m[i][j]=='X') ans[i+ret][j]=m[i][j];
			else if(m[i][j]=='#') ans[i][j]=m[i][j];
		}
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<s;j++){
			printf("%c",ans[i][j]);
		}
		puts("");
	}
	return 0;
}