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

int n;
int arr[100000];
int fenwick[100001];

void update(int pos,int val){
	while(pos<=n){
		fenwick[pos]+=val;
		pos+=(pos&-pos);
	}
}

int sum(int pos){
	int s=0;
	while(pos>0){
		s+=fenwick[pos];
		pos-=(pos&-pos);
	}
	return s;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	update(arr[n-1],1);
	int j=0;
	for(int i=n-1;i>=1;i--){
		if(arr[i]>arr[i-1]){
			update(arr[i-1],1);
		}else{
			j=i;
			break;
		}
	}
	cout<<j<<endl;
	int tmp=j;
	for(int i=0;i<j;i++){
		int q=sum(arr[i]);
		printf("%d ",q+(--tmp));
		update(arr[i],1);
	}
	return 0;
}