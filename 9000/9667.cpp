#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

#define MAX 100010
int n;
int euler[MAX];
bool val[MAX];
bool chk[MAX];
void euler_pi(){
	euler[1]=1;
	for(int i=2;i<=100000;i++){
		int x=i;
		bool tmp=false;
		for(int d=2;d<=sqrt(i);d++){
			if(x%d==0){
				tmp=true;
				while(x%d==0){
					x=x/d;
				}
				//i가 소수 p^k면 euler[i]=p^(k-1)*(p-1)=i-i/p
				if(x==1) euler[i]=i-i/d;
				//오일러 파이 함수는 곱셈함수 이다.
				else euler[i]=euler[x]*euler[i/x];
				break;
			}
		}
		//i는 소수
		if(!tmp) euler[i]=i-1;
	}
}

int main(){
	cin>>n;
	euler_pi();
	for(int i=0;i<n+1;i++){
		int x;
		scanf("%d",&x);
		val[x]=true;
	}
	long long ans=0;
	for(int i=2;i<=100000;i++){
		for(int j=i;j<=100000;j+=i){
			//i를 약수로 갖고 있는 수가 존재한다.
			if(val[j] && !chk[i]){
				ans+=euler[i];
				chk[i]=true;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}