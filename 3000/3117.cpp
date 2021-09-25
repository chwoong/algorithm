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

int n,k;
long long m;
//sparse[i][j]: 동영상 i를 틀었을 때 2^j분 이후의 동영상 번호
int sparse[100001][31];
int arr[100000];
int main(){
	scanf("%d %d %lld",&n,&k,&m);
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	for(int i=1;i<=k;i++)
		scanf("%d",&sparse[i][0]);
	//sparse[i][j]계산
	for(int j=1;j<31;j++)
		for(int i=1;i<=k;i++)
			sparse[i][j]=sparse[ sparse[i][j-1] ][j-1];
	//solve
	for(k=0;k<31;k++){
		/*2^k번 jump를 해야 함*/
		if(((long long)1<<k)&(m-1))
			for(int i=0;i<n;i++)
				arr[i]=sparse[arr[i]][k];	
	}
	for(int i=0;i<n;i++)
		printf("%d\n",arr[i]);
	return 0;
}