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

typedef pair<int,int> P;
#define INF 1000000000
int n,w;
P arr[1010];

//dp[i][j]: 첫번째 경찰차가 i번째 사건을 처리하고 
//두번째 경찰차가 j번째 사건을 처리했을 때 앞으로의 거리 합 최솟값
int dp[1010][1010];

int solve(int i,int j){
	int& ret=dp[i][j];
	if(ret!=-1) return ret;
	if(i==w || j==w) return 0;
	ret = INF;
	int c=max(i,j)+1;
	P here;
	//이번에 해결해야 하는 사건은 c번이다.
	//첫번째 경찰차가 c를 해결
	if(i==0) here=P(1,1);
	else here=arr[i];
	//here과 arr[c]와의 거리
	ret=min(ret,solve(c,j)+abs(here.first-arr[c].first)+abs(here.second-arr[c].second));
	if(j==0) here=P(n,n);
	else here=arr[j];
	ret=min(ret,solve(i,c)+abs(here.first-arr[c].first)+abs(here.second-arr[c].second));
	return ret;
	
}


int main(){
	cin>>n>>w;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=w;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		arr[i]=P(a,b);
	}
	printf("%d\n",solve(0,0));
	int a=0;
	int b=0;
	for(int i=1;i<=w;i++){
		P here;
		if(a==0) here=P(1,1);
		else here=arr[a];
		if(solve(a,b)==solve(i,b)+abs(here.first-arr[i].first)+abs(here.second-arr[i].second)){
			printf("%d\n",1);
			a=i;
		}else{
			if(b==0) here=P(n,n);
			else here=arr[b];
			if(solve(a,b)==solve(a,i)+abs(here.first-arr[i].first)+abs(here.second-arr[i].second)){
				printf("%d\n",2);
				b=i;
			}
		}
	}
	return 0;
}