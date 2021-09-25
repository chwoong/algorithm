#include <iostream>
#include <algorithm>

using namespace std;

char arr[64][64];

char same(char d1,char d2,char d3,char d4){
    if(d1==d2 &&d1==d3&&d1==d4 && d1=='1') return '1';
    else if(d1==d2 &&d1==d3&&d1==d4 && d1=='0') return '0';
    else return 'x';
}

void solve(int x,int y,int n){
    if(n==0) return;
        int temp=1;
        char a=arr[x][y];
        for(int i=x;i<x+n;i++){
            for(int j=y;j<y+n;j++){
                if(arr[i][j]!=a) {temp=0; break;}
            }
        }
        if(temp==0){
            cout << "(";
            solve(x,y,n/2);
            solve(x,y+n/2,n/2);
            solve(x+n/2,y,n/2);
            solve(x+n/2,y+n/2,n/2);
            cout << ")";
        }
        else cout << a;
}

int main(){
    int N;
    cin >>N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    solve(0,0,N);
    return 0;
}