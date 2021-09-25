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

int w,n;
int arr[5000];
int dp[800001];
int main(){
	cin>>w>>n;
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]+arr[j]<w){
				if(dp[w-arr[i]-arr[j]]==1){
					puts("YES");
					return 0;
				}
			}
		}
		for(int j=0;j<i;j++){
			dp[arr[i]+arr[j]]=1;
		}
	}
	puts("NO");
	return 0;
}