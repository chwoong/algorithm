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
#include <cstdio>
#include <fstream>
using namespace std;

int n;
int arr[5][40001];

int main(){
	arr[0][0]=1;
	for(int i=1;i<=200;i++){
		for(int j=0;j<=40000;j++){
			if(j+i*i<=40000){
			for(int k=0;k<4;k++){
				arr[k+1][j+i*i]+=arr[k][j];
			}
			}else break;
		}
	}
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		printf("%d\n",arr[1][n]+arr[2][n]+arr[3][n]+arr[4][n]);
	}
	return 0;
}