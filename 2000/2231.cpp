#include <iostream> 
#include <algorithm> 

using namespace std; 

/* sum of each digit */
int sum(int i){
    if(i<10) return i;
    return i%10 + sum(i/10);
}

int main() 
{ 
    int N, ans=0;
    cin >> N;
    for(int i=1;i<N;i++){
        if(sum(i)+i == N){
            ans=i;
            break;
        }
    }
    cout << ans;
    return 0;
}
