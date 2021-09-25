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

int n;
int arr[100000];
vector<double> v;

/*간격이 i일 때 이동거리의 합*/
long long solve(long long dist){
	long long ret=0;
	for(long long i=0;i<n;i++){
		ret+=abs(dist*i-arr[i]);
	}
	return ret;
}

int main(){
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		scanf("%d",arr+i);
	}
	int l=0;
	int h=1000000000;
	while(l+3<=h){
		int p=(l*2+h)/3;
		int q=(l+2*h)/3;
		if(solve(p)<=solve(q)) h=q;
		else l=p;
	}
	long long ans=1e15;
	for(int i=l;i<=h;i++){
		ans=min(ans,solve(i));
	}
	cout<<ans;
	
	return 0;
}