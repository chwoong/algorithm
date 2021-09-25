#include <iostream>
#include <algorithm>

using namespace std;

long long N;
long long numbelow(long long x){
    long long num(0);
    for(int i=1;i<=min(N,x);i++){
        num += min(N,(x/i));
    }
    return num;
}
int isin(long long x){
    int temp=0;
    for(long long i=2;i<=N;i++){
        if(x%i==0 && x/i<=N) {temp++; break;}
    }
    if(temp==1) return 1;
    return 0;
}

int main()
{
    long long k;
    cin>>N>>k;
    
    long long num(0);
    long long small(0), big(N*N);
    int temp=1;
    if(N==1) {cout <<1; return 0;}
    while(small+1<big){
        long long mid = (small+big)/2;
        long long a=numbelow(mid);
        long long b=numbelow(mid-1);
        if(a>=k && b>=k) big=mid;
        if(a<k) small=mid;
        if(a>=k && b<k) {temp =0;cout <<mid; break;}
    }
    if(temp){
        while(1){
            if(isin(small)) {cout<<small; break;}
            else small++;
        }
    }
}