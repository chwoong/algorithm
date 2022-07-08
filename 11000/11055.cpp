#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int A[1000];
int dp[1000];

/* A[start]�� �����ϴ� A[start]~A[N]������ �κ� �������� �� �ִ� �� ��ȯ */
int maxSum(int start){
    if(start==N-1) return A[N-1];
    int &ret = dp[start];
    if(ret != -1) return ret;
    /* maxSum(start)�� �ּҰ��� A[start]�̹Ƿ� ���� �ʱ�ȭ ���ش�.  */
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