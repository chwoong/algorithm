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
using namespace std;

#define MAX 1000000000
int n;
map<int,int> m;
int arr[100000];

void update(int pos,int val){
	while(pos<=MAX){
		m[pos]+=val;
		pos+=(pos&-pos);
	}
}

int sum(int pos){
	int s=0;
	while(pos>0){
		s+=m[pos];
		pos-=(pos&-pos);
	}
	return s;
}

int main(){
	cin>>n;
	int ans=0;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
		int val=sum(MAX)-sum(arr[i]);
		ans=max(ans,val);
		update(arr[i],1);
	}
	cout<<ans+1;
	return 0;
}