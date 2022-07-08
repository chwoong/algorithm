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

int n,kk;
int arr[100000];
//d[i][j][k]: ���� i��° �� ����,������ �ٲܱ�ȸ j, �� ���� �� �´��� k
int dp[100010][21][3];

int solve(int i,int j,int k){
	int &ret=dp[i][j][k];
	if(ret!=-1) return ret;
	ret=0;
	//�̹��� �� �ٲٸ�	
	if(i==n) return ret=0;
	int tmp;
	if((arr[i]+1)%3==k) tmp=1;
	else tmp=0;
	ret=tmp+solve(i+1,j,k);
	//�ٲ� �� �ִ�.
	if(j>0){
		//t�� �ٲ���
		for(int t=0;t<3;t++){
			if(t!=k){
				int b;
				if((arr[i]+1)%3==t) b=1;
				else b=0;
				ret=max(ret,b+solve(i+1,j-1,t));
			}
		}
	}
	return ret;
}

int main(){
	cin>>n>>kk;
	for(int i=0;i<n;i++){
		char s[5];
		scanf("%s",s);
		if(s[0]=='H') arr[i]=0;
		else if(s[0]=='P') arr[i]=1;
		else arr[i]=2;
	}
	memset(dp,-1,sizeof(dp));
	int ans=0;
	for(int t=0;t<3;t++){
		//0��°�� t�� ���� �� �̱���� ������
		int a;
		if((arr[0]+1)%3==t) a=1;
		else a=0;
		ans=max(ans,solve(1,kk,t)+a);
	}
	cout<<ans;
	return 0;
}