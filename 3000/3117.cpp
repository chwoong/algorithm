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
//sparse[i][j]: ������ i�� Ʋ���� �� 2^j�� ������ ������ ��ȣ
int sparse[100001][31];
int arr[100000];
int main(){
	scanf("%d %d %lld",&n,&k,&m);
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	for(int i=1;i<=k;i++)
		scanf("%d",&sparse[i][0]);
	//sparse[i][j]���
	for(int j=1;j<31;j++)
		for(int i=1;i<=k;i++)
			sparse[i][j]=sparse[ sparse[i][j-1] ][j-1];
	//solve
	for(k=0;k<31;k++){
		/*2^k�� jump�� �ؾ� ��*/
		if(((long long)1<<k)&(m-1))
			for(int i=0;i<n;i++)
				arr[i]=sparse[arr[i]][k];	
	}
	for(int i=0;i<n;i++)
		printf("%d\n",arr[i]);
	return 0;
}