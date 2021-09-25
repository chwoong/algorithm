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

long long n;
long long tmp;
vector<long long> p;
int main(){
	cin>>n;
	tmp=n;
	for(int i=2;i<1000000;i++){
		if(tmp%i==0){
			p.push_back(i);
			while(tmp%i==0){
				tmp/=i;
			}
		}
	}
	if(tmp!=1) p.push_back(tmp);
	int len=p.size();
	int x=1<<len;
	long long ans=0;
	while(--x){
		int num=0;
		long long mul=1;
		for(int i=0;i<len;i++){
			if(x & (1<<i)){
				num++;
				mul*=p[i];
			}
		}
		if(num%2==1) ans+=n/mul;
		else ans-=n/mul;
	}
	cout<<n-ans;
	return 0;
}