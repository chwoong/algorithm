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
#include <cstdio>
#include <fstream>
using namespace std;

int n;
int arr[1000];
//dp[i][j][k]: i��° ���ұ��� �߿� j�� �����ؼ� ���� modN ���� k�� �ǵ��� �� �� �ִ°�
bool dp[1000][501][500];

int main(){
	cin>>n;
	for(int i=1;i<=2*n-1;i++) scanf("%d",arr+i);
	dp[0][0][0]=1;
	for(int i=1;i<=2*n-1;i++){
		for(int x=0;x<=500;x++){
			for(int y=0;y<500;y++){
				dp[i][x][y]|=dp[i-1][x][y];
			}
		}
		for(int x=0;x<500;x++){
			for(int y=0;y<500;y++){
				dp[i][x+1][(y+arr[i])%n]|=dp[i-1][x][y];
			}
		}
	}
	if(dp[2*n-1][n][0]){
		int j=n;
		int k=0;
		for(int i=2*n-1;i>0;i--){
			if(dp[i-1][j][k]){
				continue;
			}else{
				printf("%d ",arr[i]);
				j--;
				k=(n+k-arr[i])%n;
			}
		}
	}else{
		puts("-1");
	}
	return 0;
}