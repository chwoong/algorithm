#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<set>
#include<stack>
#include<map>
using namespace std;

int d(int num){
	int ret=num;
	while(num>0){
		ret+=num%10;
		num=num/10;
	}
	return ret;
}

int main(){
	int f[10001]={0,};
	for(int i=1;i<=10000;i++){
		if(f[i]==0){
			printf("%d\n",i);
			for(int j=d(i);j<=10000;j=d(j)){
				f[j]=1;
			}
		} 
	}
	return 0;
}