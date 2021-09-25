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

int n;
int arr[100];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	int val=arr[n-1]-1;
	int ans=0;
	for(int i=n-2;i>=0;i--){
		if(arr[i]>=val){ ans+=(arr[i]-val); val--;}
		else{
			val=arr[i]-1;
		}
	}
	cout<<ans;
	return 0;
}