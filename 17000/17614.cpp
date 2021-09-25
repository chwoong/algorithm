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
int ans;
//숫자 i의 박수 횟수
int f(int i){
	int ret=0;
	while(i){
		int j=i%10;
		i/=10;
		if(j!=0&&j%3==0) ret++;
	}
	return ret;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		ans+=f(i);
	}
	cout<<ans;
	return 0;
}