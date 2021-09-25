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
long long x;
priority_queue<long long> q1;

int main(){
	cin>>n;
	int size=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%lld ",&x);
			q1.push(-x);
			size++;
		}
		while(size!=n){
			q1.pop();size--;
		}
	}
	cout<<-q1.top();

	return 0;
}