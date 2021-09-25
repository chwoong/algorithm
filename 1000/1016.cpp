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

int minfactor[1001001];
vector<long long> prime;

int main(){
	long long mi,ma;
	cin>> mi>>ma;
	/* min과 max사이에서 정수의 제곱으로 에라토스테네스 체 쓴다 */
	/* answer[i]: min+i가 제곱 ㄴㄴ수인가? */
	bool answer[1000001];
	memset(answer,true,sizeof(answer));
	for(long long i=2;i<1001000;i++){
		if(i*i>ma) break;
		for(long long j=mi-mi%(i*i);j<=ma;j+=(i*i)){
			if(j>=mi) answer[j-mi]=false;
		}
	}
	int num=0;
	for(long long i=0;i<=ma-mi;i++){
		if(answer[i]==true) num++;
	}
	cout<<num;
	
	return 0;
}