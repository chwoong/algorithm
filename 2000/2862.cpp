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
using namespace std;

vector<long long> fibo;
long long n;
int main(){
	cin>>n;
	fibo.push_back(1);
	fibo.push_back(2);
	for(int i=2;i<=80;i++){
		fibo.push_back(fibo[i-1]+fibo[i-2]);
	}
	while(1){
		for(int i=0;i<=80;i++){
			if(fibo[i]==n){printf("%lld",fibo[i]); return 0;}
			else if(fibo[i]>n) {n-=fibo[i-1];break;}
		}
	}
	return 0;
}