#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
using namespace std;
#define MAX 1000001
int minfactor[MAX];
int number[MAX]={0,};
int number2[MAX]={0,};
int arr[101];
int main(){
	int N;
	cin>>N;
	for(int i=2;i<MAX;i++)
		minfactor[i]=i;
	for(int i=2;i<=1000;i++){
		if(minfactor[i]==i)
			for(int j=i*i;j<MAX;j+=i)
				if(minfactor[j]==j) minfactor[j]=i;
	}
	for(int i=0;i<N;i++){
		int x;
		cin>>x;
		arr[i]=x;
		while(x!=1){
			number[minfactor[x]]++;
			x=x/minfactor[x];
		}
	}
	int result=0;
	/*최대로 가능한 gcd의 소인수 정보*/
	for(int i=2;i<MAX;i++)
		number[i]/=N;
	for(int i=0;i<N;i++){
		while(arr[i]!=1){
			number2[minfactor[arr[i]]]++;
			arr[i]=arr[i]/minfactor[arr[i]];
		}
		for(int j=2;j<MAX;j++){
			if(number[j]!=0){
				//부족하다면 count
				if(number2[j]<number[j]) result+=(number[j]-number2[j]);
			}
		}
		memset(number2,0,sizeof(number2));
	}
	int ans=1;
	for(int i=2;i<MAX;i++){
		if(number[i]!=0) {
			while(number[i]--){
				ans*=i;
			}
		}
	}
	cout<<ans<<" "<<result;
	return 0;
}