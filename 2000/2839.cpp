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

int n;
int main(){
	cin>>n;
	//i는 5kg짜리 봉지 개수
	for(int i=n/5;i>=0;i--){
		if((n-5*i)%3==0) {printf("%d",i+(n-5*i)/3); return 0;}
	}
	puts("-1");
	return 0;
}