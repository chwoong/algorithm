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
	/*��ȯ���� n�� ������ �ʴ´�*/
	ret=n;
	for(int i=0;i<square.size();i++){
		if(square[i]<n) ret=min(ret,1+solve(n-square[i]));
	}
	
	return ret;
}

int main(){
	cin>>N;	
	/*N������ �������� ������*/
	int i=1;
	while(1){
		if(i*i<=N) {square.push_back(i*i); mini[i*i]=1;i++;}
		else break;
	}
	cout<<solve(N);
	return 0;
}