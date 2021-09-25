#include <iostream>

using namespace std;

int arr[20];
int N;
int subseq(int S,int i,int temp){
    if(S==0 && i==N &&temp>0) return 1;
    else if(i==N && S!=0) return 0;
    else return subseq(S-arr[i], i+1, temp+1)+subseq(S, i+1, temp+1);
}

int main()
{
  int S,num;
  cin >> N >> S;
  for(int i=0;i<N;i++){
      cin >> arr[i];
  }
  num = subseq(S,0,0);
  if(S==0) num--;
  cout << num;
  
   return 0;
}