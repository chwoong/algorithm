#include <iostream>
#include <list>

using namespace std;

int main()
{
   list<int> q;
   int N,M;
   cin >>N >> M;
   for(int i=1;i<=N;i++){
       q.push_back(i);
   }
   int arr[50];
   int temp;
   for(int i=0;i<M;i++){
        cin >> temp;
        arr[i]=temp;
   }
   
   int ret=0;
   int x=0;
   while(x<=M-1){
        int index=0;
        list<int>::iterator it = q.begin();
        while(1){
            if(*it == arr[x]) break;
            it++;
            index++;
        }
       // cout<< "index" <<index <<endl;
        char judge;
        index>=(N-x-index) ? judge='R' : judge='L';
        switch(judge){
            case 'L':
                ret+=index;
              //  cout << index <<endl;
                while(index--){
                    int i=q.front();
                    q.pop_front();
                    q.push_back(i);
                }
                q.pop_front();
                break;
            case 'R':
                index = N-x-index;
                ret+=index;
                //cout << index <<endl;
                while(index--){
                    int i=q.back();
                    q.pop_back();
                    q.push_front(i);
                }
                q.pop_front();
                break;
        }
       x++;
   }
   cout << ret;
   return 0;
}