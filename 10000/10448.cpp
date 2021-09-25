#include <iostream>

using namespace std;

int tri[44];
int test(int n){
    for(int i=0;i<44;i++){
        for(int j=i;j<44;j++){
            for(int k=j;k<44;k++){
                if((tri[i]+tri[j]+tri[k]) == n) return 1;
            }
        }
    }
    return 0;
}

int main()
{
   
    for(int i=0;i<44;i++){
        tri[i]=(i+1)*(i+2)/2;
    }
    int K;
    cin >> K;
    for(int i=0;i<K;i++){
        int n, pro;
        cin >>n;
        pro = test(n);
        cout << pro << endl;
    }


    return 0;
}