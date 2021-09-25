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
#include<cmath>
#include<time.h>
using namespace std;

int n,k;
int arr[1000000];
int v[1000000];
long long psum[1000001];

int main(){
	cin>>n>>k;
	for(int i=0;i<k;i++){
		int x;
		scanf("%d",&x);
		arr[x]++;
	}
	for(int i=1;i<n;i++){
		if(arr[i]){
			for(int j=0;j<n;j+=i) v[j]+=arr[i];
		}
	}
	for(int i=1;i<=n;i++){
		psum[i]=psum[i-1]+v[i-1];
	}
	int q;
	cin>>q;
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		printf("%lld\n",psum[r+1]-psum[l]);
	}
	return 0;
}