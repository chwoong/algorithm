#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

int N;
int mini[100001]={0,};
vector<int> square;

int solve(int n){
	int&ret=mini[n];
	if(ret!=0) return ret;
	/*반환값은 n을 넘지는 않는다*/
	ret=n;
	for(int i=0;i<square.size();i++){
		if(square[i]<n) ret=min(ret,1+solve(n-square[i]));
	}
	
	return ret;
}

int main(){
	cin>>N;	
	/*N이하의 제곱수를 구하자*/
	int i=1;
	while(1){
		if(i*i<=N) {square.push_back(i*i); mini[i*i]=1;i++;}
		else break;
	}
	cout<<solve(N);
	return 0;
}