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

int arr[10];
int main(){
	for(int i=0;i<10;i++){
		scanf("%d",arr+i);
	}
	int sum=0;
	int ans;
	int b=100;
	for(int i=0;i<10;i++){
		sum+=arr[i];
		if(b>=(100-sum>=0?100-sum:sum-100)) {b=abs(100-sum);ans=sum;}
	}
	cout<<ans;
	return 0;
}