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

int m[10][10];
int arr[10][10];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void change(int i,int j){
	for(int k=0;k<4;k++){
		int ni=i+dx[k];
		int nj=j+dy[k];
		if(ni>=0 && ni<10 && nj>=0 & nj<10){
			arr[ni][nj]=!arr[ni][nj];
		}
	}
	arr[i][j]=!arr[i][j];
}


int main(){
	for(int i=0;i<10;i++){
		string s;
		cin>>s;
		for(int j=0;j<10;j++){
			m[i][j]=s[j];
			if(m[i][j]=='O') m[i][j]=1;
			else m[i][j]=0;
		}
	}
	int ans=101;
	for(int i=0;i<1024;i++){
		//i의 1비트가 켜져 있는 부분이 맨 윗줄 전구를 누르는 경우이다.
		int num=0;
		for(int x=0;x<10;x++)
			for(int y=0;y<10;y++)
				arr[x][y]=m[x][y];
		//먼저 맨 윗줄을 누르자.
		for(int x=0;x<10;x++){
			if(i & (1<<x)){
				change(0,x);
				num++;
			}
		}
		
		for(int x=1;x<10;x++){
			for(int y=0;y<10;y++){
				if(arr[x-1][y]==1){
					num++;
					change(x,y);
				}
			}
		}
		int sum=0;
		for(int x=0;x<10;x++){
			for(int y=0;y<10;y++){
				sum+=arr[x][y];
			}
		}
		if(sum==0){
			ans=min(ans,num);
		}
	}
	if(ans==101) cout<<-1;
	else cout<<ans;
	return 0;
}