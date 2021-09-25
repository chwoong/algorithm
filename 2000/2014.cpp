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

const long long INF = (long long)1<<31;

int k,n;
priority_queue<int,vector<int>,greater<int> > q;
int arr[100];

int main(){
	cin>>k>>n;
	int p;
	for(int i=0;i<k;i++){
		scanf("%d ",&p);
		arr[i]=p;
		q.push(p);
	}
	int prev=0;
	for(int i=0;i<n-1;i++){
		int curr=q.top();
		if(prev==curr){
			while(prev==curr){
				q.pop();
				curr=q.top();
			}
		}
		q.pop();
		prev=curr;
		for(int j=0;j<k;j++){
			long long x=(long long)curr*(long long)arr[j];
			if(x<INF) q.push((int)x);
		}
	}
	int s=q.top();
	while(prev==s){
		q.pop();
		s=q.top();
	}cout<<s;
	return 0;
}