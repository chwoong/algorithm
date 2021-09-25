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

int arr[1001];
int main(){
	int n;
	int ans=0;
	cin>>n;
	int cnt=0;
	int prev=0;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
		if(arr[prev]<arr[i]){
			ans=max(ans,arr[i]-arr[cnt]);
			prev=i;
		}else{
			cnt=i;
			prev=i;
		}
	}
	cout<<ans;
	return 0;
}