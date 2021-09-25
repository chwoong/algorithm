#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> classtime;
    for(int i=0;i<N;i++){
        int begin,end;
        cin >> begin >> end;
        classtime.push_back(make_pair(begin,end));
    }
    sort(classtime.begin(),classtime.end());
    
    priority_queue<int,vector<int>,greater<int>> room;
    room.push(classtime[0].second);
    for(int i=1;i<N;i++){
        if(room.top() <= classtime[i].first){
            room.pop();
            room.push(classtime[i].second);
        }else{
            room.push(classtime[i].second);
        }
        
    }
    
    cout << room.size();
}