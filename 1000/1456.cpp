#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

long long A,B;

bool isprime[10000001]={false,};

int main(){
	cin>>A>>B;
	//cout<<(long long)9999991*(long long)9999991<<endl;
	/* 에라토스테네스 */
	for(long long i=2;i<=4000;i++){
		if(isprime[i]==false){
			for(long long j=i*i;j<=10000000;j+=i){
				isprime[j]=true;
			}
		}
	}
	vector<long long>p;
	for(long long i=2;i<=10000000;i++){
		if(isprime[i]==false) p.push_back(i);
	}
	int ans=0;
	for(int i=0;i<p.size();i++){
		int un=1,up=0;
		long long val=1;
		while(val<(A+p[i]-1)/p[i]){
			un++;
			val=val*p[i];
		}
		val=1;
		while(val<=B){
			up++;
			val=val*p[i];
			if(val>B/p[i]) break;
		}
		//if(i<10) cout<<un<<" "<<up<<endl; 
		un=max(un,2);
		if(up>=un) ans+=(up-un+1);
	}
	cout<<ans;
	return 0;
}