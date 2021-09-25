#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
using namespace std;

char map[4][4];

int absol(int i){
	return i>0?i:-i;
}

int main(){
	int ret=0;
	for(int i=0;i<4;i++)
		cin>>map[i];
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(map[i][j]!='.')ret+=(absol((map[i][j]-'A')/4-i)+absol((map[i][j]-'A')%4-j));
		}
	}
	cout<<ret;
	return 0;
}