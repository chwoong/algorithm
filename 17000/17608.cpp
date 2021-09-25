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

int n;
int arr[100000];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	int l=0;
	int ans=0;
	for(int i=n-1;i>=0;i--){
		if(arr[i]>l) {ans++;l=arr[i];}
	}
	cout<<ans;
	return 0;
}