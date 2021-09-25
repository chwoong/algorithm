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
#include<time.h>
using namespace std;

int r,c;
char m[50][50];
int arr[5];

int main(){
	cin>>r>>c;
	for(int i=0;i<r;i++){
		string s;
		cin>>s;
		for(int j=0;j<c;j++){
			m[i][j]=s[j];
		}
	}
	for(int i=0;i<r-1;i++){
		for(int j=0;j<c-1;j++){
			int num=0;
			if(m[i][j]=='#') continue;
			if(m[i][j]=='X') num++;
			if(m[i][j+1]=='#') continue;
			if(m[i][j+1]=='X') num++;
			if(m[i+1][j]=='#') continue;
			if(m[i+1][j]=='X') num++;
			if(m[i+1][j+1]=='#') continue;
			if(m[i+1][j+1]=='X') num++;
			arr[num]++;
		}
	}
	for(int i=0;i<5;i++){
		cout<<arr[i]<<endl;
	}
	return 0;
}