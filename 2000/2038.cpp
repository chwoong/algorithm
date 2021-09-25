#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>
using namespace std;

int arr[10000000];
int main(){
	long long n;
	cin>>n;
	arr[1]=1;
	long long s=2,e=2;
	arr[2]=2;
	if(n==1) {cout<<1; return 0;}
	if(n==2) {cout<<2; return 0;}
	//arr에 저장할 값
	long long val=2;
	long long len=arr[2];
	int tmp=1;
	while(tmp){
		len=arr[val];
		while(len--){
			if(e>10000000) e++;
			else arr[e++]=val;
			if(e==n+1) {cout<<val;tmp=0;break;}
		}
		val++;
	}
	/*
	for(int i=1;i<=n;i++)
		cout<<i<<" "<<arr[i]<<endl;
	*/
	return 0;
}