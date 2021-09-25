#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>
#include<cmath>

using namespace std;

int minfactor[1000001];

int main(){
	long long m,n;
	cin>>m>>n;
	vector<int> prime;
	for(int i=1;i<=n;i++)
		minfactor[i]=i;
	for(long long i=2;i<=n;i++){
		if(minfactor[i]==i){
			for(long long j=i*i;j<=n;j+=i)
				minfactor[j]=i;
			if(i>=m) prime.push_back(i);
		}
	}
	for(int i:prime)
		printf("%d\n",i);
	
	return 0;
}