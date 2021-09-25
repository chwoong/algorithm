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

int n;
int val[10][4][4][4];
int col[10][4][4][4];
int ans=0;
int res1[5][5];
int res2[5][5];
int cache1[5][5];
int cache2[5][5];
//사용한 재료 목록
bool used[10];

//폭탄 품질
void f(){
	int x=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			switch(res2[i][j]){
				case 'R': x+=7*res1[i][j]; break;
				case 'B': x+=5*res1[i][j]; break;
				case 'G': x+=3*res1[i][j]; break;
				case 'Y': x+=2*res1[i][j]; break;
				default: break;
			}
		}
	}
	ans=max(ans,x);
}
void cal(int i,int t,int pos){
	//놓는 위치
	int x=pos/2;
	int y=pos%2;
	//val[i][4][4][t]
	//col[i][4][4][t]
	//그것을 res1,res2에 합침
	for(int a=0;a<4;a++){
		for(int b=0;b<4;b++){
			res1[a+x][b+y]+=val[i][a][b][t];
			if(res1[a+x][b+y]<0) res1[a+x][b+y]=0;
			if(res1[a+x][b+y]>9) res1[a+x][b+y]=9;
			if(col[i][a][b][t]!='W'){
				res2[a+x][b+y]=col[i][a][b][t];
			}
		}
	}
}
//앞으로 채워넣어야 할 재료개수 tmp
void solve(int tmp){
	if(tmp==0){
		f();
		return;
	}
	for(int i=0;i<n;i++){
		if(used[i]==false){
			int cache1[5][5];
			int cache2[5][5];
			//caching
			for(int j=0;j<5;j++){
				for(int k=0;k<5;k++){
					cache1[j][k]=res1[j][k];
					cache2[j][k]=res2[j][k];
				}
			}
			//i를 끼워넣어서 change
			used[i]=true;
			//반시계 방향 회전 횟수 t
			//놓는 위치 x
			for(int t=0;t<4;t++){
				for(int pos=0;pos<4;pos++){
					cal(i,t,pos);
					solve(tmp-1);
					//recover
					for(int j=0;j<5;j++){
						for(int k=0;k<5;k++){
							res1[j][k]=cache1[j][k];
							res2[j][k]=cache2[j][k];
						}
					}
				}
			}
			//recover
			used[i]=false;
		}
	}
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				scanf("%d",&val[i][j][k][0]);
			}
		}
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				char s[10];
				scanf("%s",s);
				col[i][j][k][0]=(int)s[0];
			}
		}
		for(int t=0;t<3;t++){
			for(int j=0;j<4;j++){
				for(int k=0;k<4;k++){
					val[i][j][k][t+1]=val[i][3-k][j][t];
					val[i][j][k][t+1]=val[i][3-k][j][t];
					col[i][j][k][t+1]=col[i][3-k][j][t];
					col[i][j][k][t+1]=col[i][3-k][j][t];
				}
			}
		}
	}
	solve(3);
	cout<<ans;
	return 0;
}