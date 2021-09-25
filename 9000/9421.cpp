#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<string.h>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

#define MAX 1000000

int minfactor[MAX+1];
int isans[MAX+1];

int sum(int n){
	int s=0;
	while(n){
		s+=(n%10)*(n%10);
		n/=10;
	}
	return s;
}
int solve(int i){
	int& ret=isans[i];
	if(ret!=-1) return ret;
	ret=0;
	return ret=solve(sum(i));
}

int main(){
	int n;
	cin>>n;
	/*n이하의 소수 저장*/
	vector<int> prime;
	for(int i=1;i<=n;i++)
		minfactor[i]=i;
	for(int i=2;i<=n;i++){
		if(minfactor[i]==i){
			prime.push_back(i);
			if(i<=1000)
				for(int j=i*i;j<=n;j+=i)
					if(minfactor[j]==j) minfactor[j]=i;
		}
	}
	memset(isans,-1,sizeof(isans));
	isans[1]=1;
	for(int ele:prime)
		if(solve(ele)) printf("%d\n",ele);
	return 0;
}