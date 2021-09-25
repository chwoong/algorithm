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


int t;
map<long long,long long> m;
int main(){
	cin>>t;
	for(int p=1;p<=t;p++){
		long long n,k;
		cin>>n>>k;
		m.clear();
		m[n]=1;
		while(1){
			map<long long,long long>::reverse_iterator rit=m.rbegin();
			if(k<=rit->second){
				printf("Case #%d: %lld %lld\n",p,rit->first/2ll,(rit->first-1)/2ll);
				break;
			}else{
				k-=rit->second;
				m[rit->first/2ll]+=rit->second;
				m[(rit->first-1)/2ll]+=rit->second;
			}
			m.erase(rit->first);
		}
	}
	return  0;
}