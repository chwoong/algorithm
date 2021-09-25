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

int t;
int main(){
	cin>>t;
	for(int p=1;p<=t;p++){
		long long n;
		cin>>n;
		int arr[20]={0,};
		int i=0;
		for(;i<=18;i++){
			arr[i]=n%10ll;
			n/=10ll;
			if(n==0) break;
		}
			int prev=arr[i];
			int j=i-1;
			for(;j>=0;j--){
				if(prev<=arr[j]){
					prev=arr[j];
					continue;
				}else{
					int k=j+1;
					while(arr[k]==prev){
						arr[k]--;
						k++;
					}
					j=k-2;
					break;
				}
			}
			for(;j>=0;j--){
				arr[j]=9;
			}
			printf("Case #%d: ",p);
			j=i;
		while(arr[j]==0) j--;
		for(;j>=0;j--){
				printf("%d",arr[j]);
			}
			puts("");
	}
	return  0;
}