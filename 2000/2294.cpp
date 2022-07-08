#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 101;
const int MAX_K = 10001;
const int IMPOSSIBLE = 1000000000;
 
int N, K, cost[MAX_N], dp[MAX_N][MAX_K];
 
int coin(int n, int k){
    if(n == N) return (k==0 ? 0 : IMPOSSIBLE); // base case
    if(dp[n][k] != -1) return dp[n][k]; // �̹� ����
 
    int result = coin(n+1, k);
    if(k >= cost[n]) result = min(result, coin(n, k-cost[n]) + 1);
    dp[n][k] = result; // dp �迭 �� ����
    return result;
}
 
int main(){
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%d", cost+i);
    // dp �迭 �ʱ�ȭ
    for(int i=0; i<=N; i++)
        for(int j=0; j<=K; j++)
            dp[i][j] = -1;
    // dp�� ���� ǰ
    int result = coin(0, K);
    if(result == IMPOSSIBLE) puts("-1");
    else printf("%d\n", result);
}

