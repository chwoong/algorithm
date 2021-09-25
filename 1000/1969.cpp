#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
int main(){
   int N,M;
   cin >> N>> M;
   vector <string> dna;
   for(int i=0;i<N;i++){
       string word;
       cin >> word;
       dna.push_back(word);
   }
   char arr[50];
   int distance(0);
   for(int j=0;j<M;j++){
       int a(0),c(0),g(0),t(0);
       for(int i=0;i<N;i++){
           switch(dna[i][j]){
               case 'A': a++; break;
               case 'C': c++; break;
               case 'G': g++; break;
               case 'T': t++; break;
           }
       }
       if(a>=c && a>=g && a>=t) {arr[j]='A'; distance+=(N-a);}
       else if(c>=a && c>=g && c>=t){arr[j]='C'; distance+=(N-c);}
       else if(g>=a && g>=c && g>=t){arr[j]='G'; distance+=(N-g);}
       else {arr[j]='T'; distance+=(N-t);}
   }
   for(int i=0;i<M;i++){
       cout << arr[i];
   }
   cout << '\n' << distance;
   return 0;
}