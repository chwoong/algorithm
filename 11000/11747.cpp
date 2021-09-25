#include <iostream>

using namespace std;


int main()
{
    int hanaco[1000]={0};
    int N;
    int D[1000];
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> D[i];
    }
    if(N>=3){
    for(int i=0;i<N-2;i++){
        hanaco[D[i]]=1;
        hanaco[D[i]*10+D[i+1]]=1;
        hanaco[D[i]*100+D[i+1]*10+D[i+2]]=1;
    }
    hanaco[D[N-2]]=1;
    hanaco[D[N-1]]=1;
    hanaco[D[N-2]*10+D[N-1]]=1;
    
    for(int i=0;i<1000;i++){
        if(hanaco[i] == 0){
            cout << i;
            break;
        }
    }
    }
    if(N==1){
        if(D[0]==0) cout << 1;
        else cout << 0;
    }
    if(N==2){
        if(D[0]+D[1]>1){
            if(D[0]*D[1]==0){
                cout << 1;
            }else{
                cout << 0;
            }
        }else{
            cout << 2;
        }
    }
    return 0;
}