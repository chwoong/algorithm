#include<iostream>
#include<stdio.h>
#include<cstring>	
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<set>
#include<stack>
#include<map>
using namespace std;
int minfactor[300001];
vector<int> prime(1,0);

int main(){
	/*100000번째 소수까지 찾자*/
	for(int i=1;i<=300000;i++)
		minfactor[i]=i;
	/*에라토스테네스*/
	for(int i=2;i<=300000;i++){
		if(minfactor[i]==i){
			prime.push_back(i);
			if(i<=sqrt(300000))
				for(int j=i*i;j<=300000;j+=i)
					if(minfactor[j]==j) minfactor[j]=i;
		}
	}
	while(1){
		int n;
		int tmp=0;
		scanf("%d",&n);
		if(n==0) break;
		if(n==1) {cout<<1<<endl; continue;}
		vector<int>::iterator it=lower_bound(prime.begin(),prime.end(),n);
		int it1=it-prime.begin();
		if(*it==n) tmp=1;
		int it2=lower_bound(prime.begin(),prime.end(),2*n)-prime.begin();
		printf("%d\n",(it2-it1)-tmp);
	}
	return 0;
}