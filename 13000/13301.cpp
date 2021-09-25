#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

int N;
long long arr[2];
int main(){
	cin>>N;
	arr[0]=1;
	arr[1]=1;
	for(int i=2;i<=N;i++)
		arr[(i+1)%2]=(arr[i%2]+arr[(i+1)%2]);
	cout<<2*(arr[0]+arr[1]);
	return 0;
}