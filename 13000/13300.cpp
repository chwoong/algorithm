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
	for(int i=1;i<=6;i++)
		for(int j=0;j<2;j++)
			room+=(arr[j][i]+1)/2;
	cout<<room;
	return 0;
}