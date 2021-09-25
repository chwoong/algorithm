#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    /* inputs */
    int N,M;
    cin>> N;
    long long budget;
    vector<long long>budgets;
    for(int i=0;i<N;i++){
        cin >> budget;
        budgets.push_back(budget);
    }
    cin >> M;
    
    /* quick sort */
    sort(budgets.begin(),budgets.end(),greater<long long>());
    
    /* binary search */
    long long un(0), up(budgets[0]+1),mid;
    long long sum;
    while(un+1<up){
        mid = (un+up)/2;
        sum = 0;
        for(int i=0;i<N;i++){
            if(budgets[i]>mid) sum+= mid;
            else sum+=budgets[i];
        }
        if(sum>M) up=mid;
        else un=mid;
    }
    cout << un;
    return 0;
}