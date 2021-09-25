#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<set>
#include<stdlib.h>
#include<string>
using namespace std;

int N,M;
int arr[100];
int main(){
	cin>>N>>M;
	for(int i=0;i<N;i++){
		scanf("%d",arr+i);
	}
	int ans=0;
	for(int i=0;i<N-2;i++){
		for(int j=i+1;j<N-1;j++){
			for(int k=j+1;k<N;k++){
				int tmp=arr[i]+arr[j]+arr[k];
				if(tmp<=M) ans=max(ans,tmp);
			}
		}
	}
	cout<<ans;
	return 0;
}