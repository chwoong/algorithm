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
using namespace std;

int n;
//i의 각 자릿수 합
int f(int i){
	int ret=0;
	while(i){
		ret+=i%10;
		i/=10;
	}
	return ret;
}

int main(){
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i%f(i)==0) ans++;
	}
	cout<<ans;
	return 0;
}