#include <iostream> 
#include <algorithm> 

using namespace std; 

int main() 

{ 
    int dwarf[9]; 
    int fake_1, fake_2; 
    int sum=0; 
    for(int i=0;i<9;i++){ 
        cin >> dwarf[i]; 
        sum += dwarf[i]; 
    } 

    sort(dwarf, dwarf+9); 
    for(int i=0;i<8;i++){ 
        for(int j=i+1;j<9;j++){ 
            if(sum - (dwarf[i] + dwarf[j]) == 100){ 
                fake_1=i;
                fake_2=j; 
            }  
        } 
    } 
    for(int i=0;i<9;i++){ 
         if(i!=fake_1 && i!=fake_2)
         cout << dwarf[i] << "\n";
    } 
    return 0; 

} 