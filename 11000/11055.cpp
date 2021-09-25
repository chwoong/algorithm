#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int A[1000];
int dp[1000];

/* A[start]를 포함하는 A[start]~A[N]까지의 부분 증가수열 중 최대 합 반환 */
int maxSum(int start){
    if(start==N-1) return A[N-1];
    int &ret = dp[start];
    if(ret != -1) return ret;
    /* maxSum(start)의 최소값은 A[start]이므로 값을 초기화 해준다.  */
    ret = A[start];
    for(int next=start+1; next<N; next++){
        if(A[start] < A[next]) ret = max(maxSum(next)+A[start],ret); 
    }
    return ret;
}

int main()
{
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    memset(dp,-1,sizeof(dp));
    int temp=0;
    for(int i=0;i<N;i++){
        temp = max(temp, maxSum(i));
    }
    cout << temp;
    return 0;
}