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

#define MAX 100001
int n,q;
int presum[MAX][4]={0,};

int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		presum[i][1]=presum[i-1][1];
		presum[i][2]=presum[i-1][2];
		presum[i][3]=presum[i-1][3];
		presum[i][x]+=1;
	}
	for(int i=0;i<q;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d %d %d\n",presum[b][1]-presum[a-1][1],presum[b][2]-presum[a-1][2],\
			   presum[b][3]-presum[a-1][3]);
	}
	return 0;
}