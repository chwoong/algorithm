#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
using namespace std;

/*sparse[i][j]: f를 2^j번 합성하고 i를 대입*/
int sparse[200001][20];

int main(){
	int m,q;
	cin>>m;
	for(int i=1;i<=m;i++)
		scanf("%d",&sparse[i][0]);
	//sparse table 계산
	for(int j=1;j<20;j++){
		for(int i=1;i<=m;i++){
			sparse[i][j]=sparse[ sparse[i][j-1] ][j-1];
		}
	}
	cin>>q;
	for(int i=0;i<q;i++){
		int n,x;
		scanf("%d %d",&n,&x);
		for(int k=19;k>=0;k--){
			if((1<<k)<=n){
				x=sparse[x][k];
				n-=(1<<k);
			}
		}
		printf("%d\n",x);
	}
	return 0;
}