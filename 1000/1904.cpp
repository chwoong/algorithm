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
int f[2];
int main(){
	cin>>N;
	f[0]=2;
	f[1]=1;
	for(int i=3;i<=N;i++){
		f[i%2]=(f[i%2]+f[(i+1)%2])%15746;
	}
	cout<<f[N%2];
	return 0;
}