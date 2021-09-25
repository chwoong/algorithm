#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

#define MAX 2000000

int a[MAX+1];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	long long ans=n;
	for(long long i=2;i<=MAX;i++){
		long long tmp=0;
		for(int j=i;j<=MAX;j+=i){
			tmp+=a[j];
		}
		if(tmp>=2) ans=max(ans,tmp*i);
	}
	cout<<ans;
	return 0;
}