#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;

int psum_1[401][401];
int psum_2[401][401];
int m[401][401];
int N;
int main(){
	cin>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			scanf("%d",&m[i][j]);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			psum_1[i][j]=psum_1[i-1][j-1]+m[i][j];
			psum_2[i][j]=psum_2[i-1][j+1]+m[i][j];
		}
	}
	int ans=0;
	for(int s=2;s<=N;s++){
		for(int i=1;i<=N-s+1;i++){
			for(int j=1;j<=N-s+1;j++){
				ans=max(ans,psum_1[i+s-1][j+s-1]-psum_1[i-1][j-1]-psum_2[i+s-1][j]+psum_2[i-1][j+s]);
			}
		}
	}
	cout<<ans;
}