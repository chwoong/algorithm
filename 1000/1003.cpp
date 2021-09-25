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

int n;
/*num0[i]: fibonacci(i)를 호출 시, 0가 출력되는 횟수*/
int num0[41];
int num1[41];

void fibonacci(int i){
	int& ret0 = num0[i];
	int& ret1 = num1[i];
	if(ret0!=-1) return;
	fibonacci(i-1);
	fibonacci(i-2);
	ret0=num0[i-1]+num0[i-2];
	ret1=num1[i-1]+num1[i-2];
}

int main(){
	int t;
	cin >>t;
	memset(num0,-1,sizeof(num0));
	memset(num1,-1,sizeof(num1));
	num0[0]=1; num1[0]=0;
	num0[1]=0; num1[1]=1;	
	for(int i=0;i<t;i++){
		cin>>n;
		int ret=num0[n];
		if(ret==-1) fibonacci(n);
		printf("%d %d\n",num0[n],num1[n]);
	}
	return 0;
}