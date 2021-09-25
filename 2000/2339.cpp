#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

int N;
int map[21][21];
int dp[22][22][22][22][2];

/*dir=0: 가로로, dir=1: 세로로 자름*/
int solve(int sx,int sy,int h,int w,int dir){
	int &ret=dp[sx][sy][h][w][dir];
	if(h==0 || w==0) return ret=0; 
	if(ret!=-1) return ret;
	ret=0;
	int one=0;
	int two=0;
	for(int i=sx;i<sx+h;i++){
		for(int j=sy;j<sy+w;j++){
			if(map[i][j]==1){
				one++;
				/*이번에 가로로 자름*/
				if(dir==0){
					int treasure=0;
					for(int k=sy;k<sy+w;k++)
						if(map[i][k]==2) treasure++;
					/*자를 수 있다*/
					if(treasure==0){
						if(i!=sx+h-1){
							int ret1=solve(sx,sy,i-sx,w,1);
							int ret2=solve(i+1,sy,sx+h-1-i,w,1);
							ret+=(ret1*ret2);
						}
					}
				}
				/*이번에 세로로 자름*/
				else{
					int treasure=0;
					for(int k=sx;k<sx+h;k++)
						if(map[k][j]==2) treasure++;
					/*자를 수 있다*/
					if(treasure==0){
						if(j!=sy+w-1){
							int ret1=solve(sx,sy,h,j-sy,0);
							int ret2=solve(sx,j+1,h,sy+w-1-j,0);
							ret+=(ret1*ret2);
						}
					}
				}
			}
			if(map[i][j]==2){
				two++;
			}
		}
	}
	if(one==0 && two==0) return ret=0;
	if(one==0 && two==1) return ret=1;
	if(one==0 && two>1) return ret=0;
	return ret;
}

int main() {
	cin>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin>>map[i][j];
	memset(dp,-1,sizeof(dp));
	//cout<<dp[1][1][3][8][0]<<endl;
	int count=solve(1,1,N,N,0)+solve(1,1,N,N,1);
	cout<<(count==0?-1:count);
	return 0;
}