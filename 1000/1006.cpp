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
using namespace std;

int t;
int n,w;
int a[10010][2];
int dp[10010][3];
int solve(int i,int s){
	int&ret=dp[i][s];
	if(ret!=-1) return ret;
	if(s==0){
		ret=solve(i,1)+1;
		ret=min(ret,solve(i,2)+1);
		if(a[n+1-i][0]+a[n+1-i][1]<=w) ret=min(ret,solve(i-1,0)+1);
		if(a[n+1-i][0]+a[n+2-i][0]<=w && a[n+1-i][1]+a[n+2-i][1]<=w) ret=min(ret,solve(i-2,0)+2);
	}
	else if(s==1){
		ret=solve(i-1,0)+1;
		if(a[n+1-i][0]+a[n+2-i][0]<=w) ret=min(ret,solve(i-1,2)+1);
	}
	else if(s==2){
		ret=solve(i-1,0)+1;
		if(a[n+1-i][1]+a[n+2-i][1]<=w) ret=min(ret,solve(i-1,1)+1);
	}
	return ret;
}

int main(){
	cin>>t;
	while(t--){
		int ans;
		scanf("%d %d",&n,&w);
		int arr[20001]={0,};
		for(int i=1;i<=2*n;i++)
			scanf("%d",arr+i);
		/*case1
		w 9 10 11 ... 16
		w 1  2  3 ... 8 */
		a[0][0]=w; a[0][1]=w;
		for(int i=1;i<=n;i++){
			a[i][0]=arr[i];
			a[i][1]=arr[n+i];
		}
		memset(dp,-1,sizeof(dp));
		dp[1][1]=1; dp[1][2]=1; dp[0][0]=0;
		if(a[n][0]+a[n][1]>w) dp[1][0]=2;
		else dp[1][0]=1;
		ans=solve(n+1,0);
		/*case2
		w 9 10 ... 15 16
		8 1  2 ...  7 w */
		for(int i=1;i<=n;i++){
			a[i][0]=arr[i];
			a[i][1]=arr[n+i];
		}
		a[0][1]=w; a[0][0]=arr[n]; a[n][0]=w;
		memset(dp,-1,sizeof(dp));
		dp[1][1]=1; dp[1][2]=1; dp[0][0]=0;
		if(a[n][0]+a[n][1]>w) dp[1][0]=2;
		else dp[1][0]=1;
		ans=min(ans,solve(n+1,0));
		/*case3
		16 9 10 ... 15 w
		w  1  2 ...  7 8 */
		for(int i=1;i<=n;i++){
			a[i][0]=arr[i];
			a[i][1]=arr[n+i];
		}
		a[0][0]=w; a[0][1]=arr[2*n]; a[n][1]=w;
		memset(dp,-1,sizeof(dp));
		dp[1][1]=1; dp[1][2]=1; dp[0][0]=0;
		if(a[n][0]+a[n][1]>w) dp[1][0]=2;
		else dp[1][0]=1;
		ans=min(ans,solve(n+1,0));
		/*case4
		16 9 10 11 ... w
		8  1  2  3 ... w */
		for(int i=1;i<=n;i++){
			a[i][0]=arr[i];
			a[i][1]=arr[n+i];
		}
		a[0][0]=arr[n]; a[0][1]=arr[2*n]; a[n][0]=w; a[n][1]=w;
		memset(dp,-1,sizeof(dp));
		dp[1][1]=1; dp[1][2]=1; dp[0][0]=0;
		if(a[n][0]+a[n][1]>w) dp[1][0]=2;
		else dp[1][0]=1;
		ans=min(ans,solve(n+1,0));
		//end case
		printf("%d\n",ans-2);
	}
	return 0;
}