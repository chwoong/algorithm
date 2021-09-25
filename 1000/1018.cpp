#include <iostream>

using namespace std;

int mini=64;

int main()
{
   int N, M;
   char arr[50][50];
   cin >> N >> M;
   for(int i=0;i<N;i++){
       cin >> arr[i];
   }
   
   for(int i=0;i<N-7;i++){
       for(int j=0;j<M-7;j++){
           int col=0;
           for(int m=j;m<j+8;m++){
               for(int n=i;n<i+8;n++){
                   if((n+m+1)%2 && arr[n][m]=='B') col++;
                   if((n+m)%2 && arr[n][m]=='W') col++;
               }
           }
           if(64-col < col) col = 64-col;
           if(col<mini) mini=col;
       }
   }
   cout << mini;
   return 0;
}