#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int n;
int s[100], t[100], b[100];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %d %d",s+i,t+i,b+i);
	}
	int num=0;
	for(int i=1;i<=1000;i++){
		int tmp=0;
		for(int j=0;j<n;j++){
			if(s[j]<=i && i<=t[j]) tmp+=b[j];
		}
		num=max(num,tmp);
	}
	cout<<num;
	return 0;
}