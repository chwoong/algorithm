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
#include <cstdio>
#include <fstream>
using namespace std;

int n,k;
int arr[100000];

int main(){
	cin>>n>>k;
	int m=-100000000;
	int ret=0;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",arr+i);
		if(i<k-1){
			ret+=arr[i];
		}else{
			ret+=arr[i];
			m=max(m,ret);
			ret-=arr[i-k+1];
		}
	}
	cout<<m;
	return 0;
}