#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

priority_queue<int,vector<int>,greater<int> > pq;

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		if(x==0) {
			if(pq.empty()) cout<<0<<"\n";
			else {
				cout<<pq.top()<<"\n"; pq.pop();
			}
		}
		else pq.push(x);
	}
	return 0;
}