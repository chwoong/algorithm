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
int map[2500][2500];
int arr[3]={0,};

int solve(int i,int j,int N){
	int a(0),b(0),c(0);
	if(N==1) return map[i][j];
	for(int l=0;l<N;l+=N/3){
		for(int m=0;m<N;m+=N/3){
			int x=solve(i+l,j+m,N/3);
			if(x==-1) a++;
			if(x==0) b++;
			if(x==1) c++;
		}
	}
	if(a==9) return -1;
	if(b==9) return 0;
	if(c==9) return 1;
	else{
		arr[0]+=a;
		arr[1]+=b;
		arr[2]+=c;
		return 2;
	}
}

int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d ",&map[i][j]);
		}
	}
	int x=solve(0,0,N);
	if(x==-1) arr[0]++;
	if(x==0) arr[1]++;
	if(x==1) arr[2]++;
	for(int i=0;i<3;i++)
		printf("%d\n",arr[i]);
	return 0;
}