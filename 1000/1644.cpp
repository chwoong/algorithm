#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>
#include<cmath>

using namespace std;

int minfactor[4000001];

int main(){
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		minfactor[i]=i;
	}
	/* n������ �Ҽ��� �˾ƺ���(�����佺�׳׽�) */
	
	vector<int> prime;
	for(long long i=2;i<=n;i++){
		/* i�� �Ҽ��̴�. */ 
		if(minfactor[i]==i){
			for(long long j=i*i;j<=n;j+=i)
				minfactor[j]=i;
			prime.push_back(i);
		}
	}
	/* ������ �Ҽ��� ������ ��Ÿ�� �� �ִ� ����� �� ��� */
	int val=0;
	int len=prime.size();
	for(int i=0;i<len;i++){
		long long sum=0;
		if(prime[i]==n) {val++;}
		if(prime[i]>n/2) continue;
		for(int j=i;j<len;j++){
			sum += prime[j];
			if(sum==n) {val++; break;}
			else if(sum>n) break;
		}
	}
	cout<< val;
	return 0;
}