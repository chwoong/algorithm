#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

long long k;
int m,n;
vector<int> v0;

vector<int> multi(vector<int> a,vector<int>b){
	vector<int> ret(m,0);
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			if(a[i]*b[j]){
				ret[(i*j)%m]=1;
			}
		}
	}
	return ret;
}

vector<int> solve(long long k){
	if(k==1)  return v0;
	if(k%2){
		vector<int> a=solve((k-1)/2);
		a=multi(a,a);
		a=multi(a,v0);
		return a;
	}else{
		vector<int> a=solve(k/2);
		a=multi(a,a);
		return a;
	}
}

int main(){
	cin>>k;
	cin>>m>>n;
	v0.assign(m,0);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v0[x]=1;
	}
	vector<int> ans=solve(k);
	for(int i=0;i<m;i++){
		if(ans[i]) printf("%d ",i);
	}
	return 0;
}