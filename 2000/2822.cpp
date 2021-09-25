#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

typedef pair<int,int> P;
priority_queue<P> pq;
vector<int> v;
int x,sum(0);
int main(){
	for(int i=1;i<=8;i++){
		cin>>x;
		pq.push(P(x,i));
	}
	int i=5;
	while(i--){
		P top=pq.top();
		pq.pop();
		v.push_back(top.second);
		sum+=top.first;
	}
	sort(v.begin(),v.begin()+5);
	cout<<sum<<endl;
	for(int ele:v)
		cout<<ele<<" ";
	return 0;
}