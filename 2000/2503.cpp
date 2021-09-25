#include <iostream>

using namespace std;

int main()
{
   int N;
   cin>>N;
   int *t=new int[N];
   int **arr = new int *[N];
   for(int i=0;i<N;i++){
       arr[i]=new int[3];
   }
   int *s = new int[N];
   int *b = new int[N];
   int tmp(0), s_num(0), b_num(0);
   int num=100;
   /* input data */
   for(int i=0;i<N;i++){
       cin >> t[i] >> s[i] >> b[i];
       arr[i][2] = t[i]%10;
       arr[i][1] = (t[i]/10)%10;
       arr[i][0] = t[i]/100;
   }
   
   /* test all numbers */
   while(num<=999){
       int x=0;
       int n[3];
       n[2] = num%10;
       n[1] = (num/10)%10;
       n[0] = num/100;
       if(n[2]!=n[1] && n[0]!=n[1] && n[2]!=n[0] && n[2]*n[1]*n[0]){
        /* check the conditions */
        for(int i=0;i<N;i++){
                s_num=b_num=0;
            for(int j=0;j<3;j++){
                   if(arr[i][j] == n[j]) s_num++;
            }
             for(int j=0;j<3;j++){
                   for(int k=0;k<3;k++){
                       if(arr[i][j] == n[k]) b_num++;
                   }
            }
            b_num -= s_num;
            if(s_num==s[i] && b_num ==b[i]) x++;
        }
        if(x == N)  tmp++;
       }
       
       num++;
   }
   cout << tmp;
   for(int i=0;i<N;i++){
       delete [] arr[i];
   }
   delete [] arr;
   delete [] t;
   delete [] s;
   delete [] b;
   return 0;
}