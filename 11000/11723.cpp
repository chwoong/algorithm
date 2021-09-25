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

int myset=0;

int main(){
	int n,x;
	char c[7];
	scanf("%d",&n);
	while(n--){
		scanf("%s",c);
		switch(c[1]){
			case 'd':
				scanf("%d",&x);
				myset|=(1<<x);
				break;
			case 'e':
				scanf("%d",&x);
				myset&=~(1<<x);
				break;
			case 'h':
				scanf("%d",&x);
				if((myset|(1<<x))==myset) puts("1");
				else puts("0");
				break;
			case 'o':
				scanf("%d",&x);
				myset^=(1<<x);
				break;
			case 'l':
				myset=(1<<21)-2;
				break;
			case 'm':
				myset=0;
				break;
		}
	}
}