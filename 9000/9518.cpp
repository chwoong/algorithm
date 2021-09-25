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

int r,c;
int m[50][50];
int dx[8]={1,1,1,0,-1,-1,-1,0};
int dy[8]={1,0,-1,-1,-1,0,1,1};
int main(){
	cin>>r>>c;
	for(int i=0;i<r;i++){
		string s;
		cin>>s;
		for(int j=0;j<c;j++){
			m[i][j]=s[j];
		}
	}
	int num=0;
	int num1=0;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(m[i][j]=='o'){
				for(int k=0;k<8;k++){
					int ni=i+dx[k];
					int nj=j+dy[k];
					if(ni>=0 &&ni<r && nj>=0 &&nj<c && m[ni][nj]=='o') num++;
				}
			}else{
				int tmp=0;
				for(int k=0;k<8;k++){
					int ni=i+dx[k];
					int nj=j+dy[k];
					if(ni>=0 &&ni<r && nj>=0 &&nj<c && m[ni][nj]=='o') tmp++;
				}
				num1=max(tmp,num1);
			}
		}
	}
	cout<<num/2+num1;
	return 0;
}