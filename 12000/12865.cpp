#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int weight[101];
int value[101];
int cache[101][1000000];

//(num+1) ~ N까지 mass의 여유무게가 남아있을 때의 최대가치
int findValue(int num,int mass){
    if(mass<=0) return 0;
    else if(num==N-1 && weight[N]<=mass) return value[N];
    else if(num==N-1 && weight[N]>mass) return 0;
    
    int &ret=cache[num][mass];
    if(ret != -1) return ret;
    if(mass >= weight[num+1]) ret =max(findValue(num+1,mass), findValue(num+1,mass-weight[num+1])+value[num+1]);
    else ret = findValue(num+1,mass);
    return ret;
}

int main()
{
    //inputs
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> weight[i+1] >> value[i+1];
    }
    //setting cache
    for(int i=0;i<101;i++){
        for(int j=0;j<K+10;j++){
            cache[i][j] = -1;
        }
    }
    
    //top-down
    cout << findValue(0,K);
    
    return 0;
}