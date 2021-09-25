#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;

int r,c;
char map[20][20];
char nmap[20][20];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
	cin>>r>>c;
	memset(map,'.',sizeof(map));
	for(int i=1;i<=r;i++){
		string s;
		cin>>s;
		for(int j=1;j<=c;j++){
			map[i][j]=s[j-1];
		}
	}
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(map[i][j]=='X'){
				int num=0;
				for(int k=0;k<4;k++){
					if(map[i+dx[k]][j+dy[k]]=='.') num++;
				}
				if(num>2) nmap[i][j]='.';
				else nmap[i][j]='X';
			}
			else nmap[i][j]='.';
		}
	}
	int pr(20),qr(0),pc(20),qc(0);
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(nmap[i][j]=='X'){
				pr=min(pr,i);
				qr=max(qr,i);
				pc=min(pc,j);
				qc=max(qc,j);
			}
		}
	}
	for(int i=pr;i<=qr;i++){
		for(int j=pc;j<=qc;j++){
			cout<<nmap[i][j];
		}
		cout<<endl;
	}
	return 0;
}