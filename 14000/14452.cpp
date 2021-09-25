#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<cmath>
#include<time.h>
using namespace std;

int n,t;
int d[10000];

int main(){
	cin>>n>>t;
	for(int i=0;i<n;i++){
		scanf("%d",d+i);
	}
	int lo=0;
	int hi=n;
	while(lo+1<hi){
		int mid=(lo+hi)/2;
		//k=mid일때 가능한지 확인
		priority_queue<int,vector<int>,greater<int> > q;
		for(int i=0;i<mid;i++){
			q.push(0);
		}
		for(int i=0;i<n;i++){
			int x=q.top();
			q.pop();
			q.push(x+d[i]);
		}
		int a=0;
		while(!q.empty()){
			a=max(a,q.top());
			q.pop();
		}
		if(a<=t) hi=mid;
		else lo=mid;
	}
	cout<<hi;
	return 0;
}