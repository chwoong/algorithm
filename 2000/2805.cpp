#include <cstdio>
using namespace std;
 
int main(){
    int N, M, height[1000000];
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%d", height+i);
    
    // ������ �Ұ����� ����� hi�� ������ �ִ����� �����ϰ� ����
    int lo = 0, hi = 1000000000;
    // �̺� Ž�� ����
    while(lo+1 < hi){
        int mid = (lo+hi)/2;
        // �� ������ ���� mid�� ���ܱ� ���� ������ �� ����� ���� �� ���ϱ�
        long long sum = 0;
        for(int i=0; i<N; i++)
            if(height[i] > mid) sum += height[i] - mid;
        // mid�� M �̻��� ���̸� ������ �� ����
        if(sum >= M) lo = mid;
        // mid�� M �̻��� ���̸� ������ �� ����
        else hi = mid;
    }
    printf("%d\n", lo);
}