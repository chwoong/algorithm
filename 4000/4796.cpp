#include <iostream>
using namespace std;
int main(){
    int i=1,L,P,V;
    while(1){
        cin >> L >> P >> V;
        if(L+P+V==0) break;
        int use=(V/P)*L+(V%P>=L ? L : V%P);
        cout << "Case " << i << ": "<<use<<endl;
        i++;
    }
    return 0;
}