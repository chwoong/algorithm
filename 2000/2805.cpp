#include <cstdio>
using namespace std;
 
int main(){
    int N, M, height[1000000];
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%d", height+i);
    
    // 무조건 불가능한 경우인 hi는 가능한 최댓값으로 설정하고 시작
    int lo = 0, hi = 1000000000;
    // 이분 탐색 시작
    while(lo+1 < hi){
        int mid = (lo+hi)/2;
        // 각 나무에 대해 mid가 절단기 설정 높이일 때 계산해 길이 합 구하기
        long long sum = 0;
        for(int i=0; i<N; i++)
            if(height[i] > mid) sum += height[i] - mid;
        // mid로 M 이상의 길이를 가져갈 수 있음
        if(sum >= M) lo = mid;
        // mid로 M 이상의 길이를 가져갈 수 없음
        else hi = mid;
    }
    printf("%d\n", lo);
}