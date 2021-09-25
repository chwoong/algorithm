#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
using namespace std;

int main(){
	int N,K;
	cin>>N>>K;
	
	int minfactor[1001];
	for(int i=2;i<=N;i++)
		minfactor[i]=i;
	int k=0;
	for(int i=2;i<=N;i++){
		if(minfactor[i]==i){
			k++;
			if(k==K){cout<<i; return 0;}
			for(int j=i*i;j<=N;j+=i)
				if(minfactor[j]==j){
					k++;
					minfactor[j]=i;
					if(k==K){cout<<j; return 0;}
				}
		}
	}
	return 0;
}