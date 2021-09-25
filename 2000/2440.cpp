#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=1;j<=n-i;j++)
			printf("*");
		cout<<'\n';
	}
	return 0;
}