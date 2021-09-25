#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
//1000^i를 반환한다
long long func(int i){
	long long ret=1;
	while(i--){
		ret*=1000;
	}
	return ret;
}
int main(){
	cin>>N;
	while(N--){
		int a,b,x;
		long long vala(0),valb(0);
		scanf("%d",&a);
		while(a--){
			scanf("%d",&x);
			vala+=func(x-1);
		}
		scanf("%d",&b);
		while(b--){
			scanf("%d",&x);
			valb+=func(x-1);
		}
		if(vala>valb) printf("A\n");
		else if(vala==valb) printf("D\n");
		else printf("B\n");
	}
	return 0;
}