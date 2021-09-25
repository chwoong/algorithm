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
using namespace std;

int m,n;
unsigned long long ans;
int arr[100000];
int main(){
	cin>>m>>n;
	int l=0;
	int h=0;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
		h=max(h,arr[i]);
	}
	while(l+1<h){
		int mid=(l+h)/2;
		long long sum=0;
		for(int i=0;i<n;i++){
			if(arr[i]>=mid) sum+=(arr[i]-mid);
		}
		if(sum>m) l=mid;
		else h=mid;
	}
	priority_queue<int> pq;
	for(int i=0;i<n;i++){
		if(arr[i]<=h) pq.push(arr[i]);
		else {pq.push(h); m-=(arr[i]-h);}
	}
	while(m--){
		int x=pq.top();
		pq.pop();
		pq.push(x-1);
	}
	while(!pq.empty()){
		unsigned long long a=pq.top();
		pq.pop();
		ans+=a*a;
	}
	cout<<ans;
	return 0;
}