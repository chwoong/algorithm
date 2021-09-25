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
//n이 몇자리수인가
int t=0;
long long arr[10];

//10^i
long long ten(int i){
	long long ret=1;
	for(int j=0;j<i;j++){
		ret*=10ll;
	}
	return ret;
}

void f(int x,int num){
	long long k=n/ten(x);
	long long i=k%10;
	long long j=k/10ll;
	long long m=n%ten(x);
	if(num==0){
		if(x==t-1) return;
		if(num<i){
			arr[num]+=j*ten(x);
		}else if(num==i){
			if(j!=0) arr[num]+=(j-1)*ten(x);
			arr[num]+=(m+1);
		}
		return;
	}
	if(num<i){
		arr[num]+=(j+1)*ten(x);
	}else if(num==i){
		arr[num]+=j*ten(x);
		arr[num]+=(m+1);
	}else{
		if(j!=0) arr[num]+=j*ten(x);
	}
}

int main(){
	cin>>n;
	long long k=n;
	while(k){
		t++;
		k/=10;
	}
	//x번째 자리수에 숫자 num이 몇번나올까
	for(int x=0;x<t;x++){
		for(int num=0;num<10;num++){
			f(x,num);
		}
	}
	for(int i=0;i<10;i++){
		cout<<arr[i]<<' ';
	}
	return 0;
}