#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

long long K,N;

int main(){
	cin>>K>>N;
	vector<long long> v;
	for(int i=0;i<K;i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end(),greater<int>());
	long long h=v[0];
	if(K==N && v[0]==v[v.size()-1]) {cout<<v[0];}
	else{
		long long l(1),h(v[0]);
		while(l+1<h){
			long long ret=0;
			long long mid=(l+h)/2;
			for(int i=0;i<v.size();i++){
				ret+=v[i]/mid;
			}
			if(ret<N) h=mid;
			else l=mid;
		}
		cout<<l;
	}
	return 0;
}