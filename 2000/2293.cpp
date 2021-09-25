#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>
using namespace std;

int n,k;
int coin[100];
/*dp[i]: i원을 만드는 가짓수*/
/*dp[i][j]: 0~(j-1)번째 동전만 사용해서
i원을 만드는 가짓수
dp[i][j]=
for(x){
	sum+=dp[i-x*coin[j]][j-1]
}

따라서 바로 전꺼만 필요하고 슬라이딩 윈도우 방식으로 풀 수 있다.
*/
int dp[2][10001]={0,};

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++)
		scanf("%d",coin+i);
	dp[0][0]=1;
	for(int t=coin[0];t<=k;t+=coin[0]){
		dp[0][t]=1;
	}
	for(int j=1;j<n;j++){
		for(int i=0;i<=k;i++){
			dp[j%2][i]=dp[(j-1)%2][i];
			for(int t=coin[j];t<=i;t+=coin[j])
				dp[j%2][i]+=dp[(j-1)%2][i-t];
		}
	}
	cout<<dp[(n-1)%2][k];
	return 0;
}