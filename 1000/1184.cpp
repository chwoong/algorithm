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

#define W 2500000
int n;
int val[51][51];
int presum[51][51];
int num[2*W]={0,};

long long ans=0;
int f(int i,int j,int x,int y){
	return presum[x][y]-presum[i-1][y]-presum[x][j-1]+presum[i-1][j-1];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&val[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			presum[i][j]=presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1]+val[i][j];
		}
	}
	for(int x=1;x<n;x++){
		for(int y=1;y<n;y++){
			// '\'¹æÇâ °è»ê
			for(int i=1;i<=x;i++){
				for(int j=1;j<=y;j++){
					//(i,j)~(x,y)ÀÇ ³ÐÀÌ
					num[f(i,j,x,y)+W]++;
				}
			}
			for(int i=x+1;i<=n;i++){
				for(int j=y+1;j<=n;j++){
					ans+=num[f(x+1,y+1,i,j)+W];
				}
			}
			for(int i=1;i<=x;i++){
				for(int j=1;j<=y;j++){
					//(i,j)~(x,y)ÀÇ ³ÐÀÌ
					num[f(i,j,x,y)+W]--;
				}
			}
			// '/'¹æÇâ °è»ê
			for(int i=1;i<=x;i++){
				for(int j=y+1;j<=n;j++){
					//(i,j)~(x,y)ÀÇ ³ÐÀÌ
					num[f(i,y+1,x,j)+W]++;
				}
			}
			for(int i=x+1;i<=n;i++){
				for(int j=1;j<=y;j++){
					ans+=num[f(x+1,j,i,y)+W];
				}
			}
			for(int i=1;i<=x;i++){
				for(int j=y+1;j<=n;j++){
					//(i,j)~(x,y)ÀÇ ³ÐÀÌ
					num[f(i,y+1,x,j)+W]--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}