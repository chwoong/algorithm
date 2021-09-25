#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    /* inputs */
    int N,M;
    cin>> N >>M;
    long long lesson;
    vector<long long>lessons;
    for(int i=0;i<N;i++){
        cin >> lesson;
        lessons.push_back(lesson);
    }
    
    /* binary search */
    long long un(lessons[0]-1), up(1000000000),mid;
    long long sum;
    while(un+1<up){
        mid = (un+up)/2;
        sum = 0;
        int temp=0;
        for(int i=0;i<N;i++){
            sum+=lessons[i];
            if(sum>mid) {temp++; sum=0; i--;}
            if(temp==M) break;
        }
        if(temp==M) un=mid;
        else up=mid;
    }
    cout << up;
    return 0;
}