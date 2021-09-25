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

int arr[10000];
int val[10000];
int m,k;
int cnt=1;
void solve(int i){
	if(i>=m/2) arr[i]=val[cnt++];
	else{
		solve(i*2);
		arr[i]=val[cnt++];
		solve(i*2+1);
	}
}

int main(){
	cin>>k;
	m=1;
	int t=k;
	while(t--) m*=2;
	for(int i=1;i<m;i++){
		scanf("%d",val+i);
	}
	solve(1);
	cnt=1;
	for(int i=1;i<=k;i++){
		int tmp=i-1;
		int a=1;
		while(tmp--) a*=2;
		while(a--){
			printf("%d ",arr[cnt]);
			cnt++;
		}
		printf("\n");
	}
	return 0;
}