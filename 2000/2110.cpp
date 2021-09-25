#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N,C;
    cin >> N >>C;
    long long house;
    vector <long long> houses;
    
    for(int i=0;i<N;i++){
        cin >> house;
        houses.push_back(house);
    }
    sort(houses.begin(),houses.end());

    long long near(1),far(1000000000),mid;
    
    while(near+1<far){
        mid=(near+far)/2;
        long long sum(0);
        int temp(0);
        for(int i=0;i<N-1;i++){
            sum+=houses[i+1]-houses[i];
            if(sum>=mid){sum=0;temp++;}
            if(temp==C-1){break;}
        }
        if(temp==C-1) near=mid;
        else far=mid;
    }
    cout << near;
    return 0;
}