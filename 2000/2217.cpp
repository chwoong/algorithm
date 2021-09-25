#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

int N;
int arr[100000];
int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		scanf("%d",arr+i);
	int m=0;
	sort(arr,arr+N);
	for(int i=0;i<N;i++){
		m=max(m,arr[i]*(N-i));
	}	
	cout<<m;
	return 0;
}