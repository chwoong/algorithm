#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

int N,K,room;
int arr[2][7];
int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++){
		int s,y;
		scanf("%d %d",&s,&y);
		arr[s][y]++;
	}
	room+=(arr[0][1]+arr[1][1]+arr[0][2]+arr[1][2]+K-1)/K;
	for(int j=0;j<2;j++)
		for(int i=2;i<=3;i++)
			room+=(arr[j][2*i]+arr[j][2*i-1]+K-1)/K;
	cout<<room;
	return 0;
}