#include<iostream>
#include <stdio.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	int a,b;
	for(int i=0;i<t;i++){
		scanf("%d %d",&a,&b);
		printf("%d\n",a+b);
	}
	
	return 0;
}