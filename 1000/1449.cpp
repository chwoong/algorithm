#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int N,L;
int arr[1001];

int main(){
	cin>>N>>L;
	int num=0;
	double cover=-1;
	for(int i=1;i<=N;i++)
		cin>>arr[i];
	sort(&arr[1],&arr[N+1]);
	for(int i=1;i<=N;i++)
		if(cover<arr[i]){
			num++;
			cover=arr[i]+L-0.5;
		}
	cout<<num;
	return 0;
}