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
#include<time.h>
using namespace std;

int a[10];
int b[10];
int x,y;
int main(){
	for(int i=0;i<10;i++){
		scanf("%d",a+i);
	}
	bool flag=false;
	for(int i=0;i<10;i++){
		scanf("%d",b+i);
		if(a[i]==b[i]) {x++; y++;}
		else if(a[i]>b[i]) x+=3;
		else y+=3;
	}
	printf("%d %d\n",x,y);
	if(x==y){
		for(int i=9;i>=0;i--){
			if(a[i]<b[i]) {puts("B");return 0;}
			else if(a[i]>b[i]) {puts("A");return 0;}
		}
		puts("D");
	}
	else if(x>y) puts("A");
	else puts("B");
	return 0;
}