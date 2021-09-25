#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector <pair<int,int>> work;
    for(int i=0;i<N;i++){
        int d,w;
        cin >> d >> w;
        work.push_back(make_pair(w,d));
    }
    sort(work.begin(),work.end(),greater<pair<int,int>>());
    
    int day[1001]={0};
    for(int i=0;i<N;i++)
        for(int j=work[i].second ; j>=1 ; j--)
            if(day[j]==0){ day[j] = work[i].first;break;}
        
    
    int sum(0);
    for(int i=1;i<1001;i++){
        sum+=day[i];
    }
    cout << sum;
    return 0;
}