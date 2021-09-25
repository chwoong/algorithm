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

long long comb[30][30];
//mCn±¸ÇÏ±â
int main(){
	comb[0][0]=1;
	for(int m=1;m<=29;m++){
		for(int n=0;n<=m;n++){
			if(n==0) comb[m][n]=1;
			else comb[m][n]=comb[m-1][n]+comb[m-1][n-1];
		}
	}
	int t;
	cin>>t;
	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);
		printf("%lld\n",comb[m][n]);
	}
	return 0;
}