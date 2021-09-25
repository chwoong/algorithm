#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

int N;
long long arr[1024];
int n[10];
bool val[10];
long long ans=0;
int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		long long x;
		int a=0;
		scanf("%lld",&x);
		memset(val,false,sizeof(val));
		while(x!=0){
			val[x%10]=true;
			x/=10;
		}
		for(int i=0;i<10;i++){
			if(val[i]) a+=(1<<i);
		}
		arr[a]+=1;
	}
	for(int i=0;i<1024;i++){
		long long tmp=0;
		for(int j=i;j<1024;j++){
			if(arr[i]&&arr[j]){
				if(i==j) tmp+=arr[i]*(arr[i]-1)/2;
				else if(i&j) tmp+=arr[i]*arr[j];
			}
		}
		ans+=tmp;
	}
	cout<<ans;
	
	return 0;
}