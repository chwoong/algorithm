#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>

using namespace std;

int n;
long long sum;
/* 값이 작은 순서대로 합쳐야한다. */
priority_queue<long long> q;

int main(){
	cin>>n;
	long long x;
	for(int i=0;i<n;i++){
		scanf("%lld",&x);
		q.push(-x);
	}
	if(n==1) cout<< 0;
	else{
		while(q.size()!=1){
			long long a=q.top();
			q.pop();
			long long b=q.top();
			q.pop();
			sum-=(a+b);
			q.push(a+b);
		}
		cout<<sum;
	}
	return 0;
}