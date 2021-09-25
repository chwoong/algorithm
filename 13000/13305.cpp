#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<string.h>
using namespace std;

int N;
int road[100000];
int val[100000];
long long ans=0;
int main(){
	cin>>N;
	for(int i=0;i<N-1;i++)
		scanf("%d",road+i);
	for(int i=0;i<N;i++)
		scanf("%d",val+i);
	long long m=val[0];
	for(int i=0;i<N-1;i++){
		if(val[i]<=m) m=val[i];
		ans+=m*road[i];
	}
	cout<<ans;
	return 0;
}