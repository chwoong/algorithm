#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
using namespace std;

int arr[100001]={0,};

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d ",&x);
		arr[i]=arr[i-1]+x;
	}
	int num;
	cin>>num;
	while(num--){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",arr[b]-arr[a-1]);
	}
	return 0;
}