#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<string.h>
#include<set>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a,b;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(s=="KBS1") a=i;
		else if(s=="KBS2") b=i;
	}
	if(a<b){
		for(int i=0;i<a;i++)
			printf("1");
		for(int i=0;i<a;i++)
			printf("4");
		for(int i=0;i<b;i++)
			printf("1");
		for(int i=0;i<b-1;i++)
			printf("4");
	}else{
		for(int i=0;i<b;i++)
			printf("1");
		for(int i=0;i<b;i++)
			printf("4");
		for(int i=0;i<a;i++)
			printf("1");
		for(int i=0;i<a;i++)
			printf("4");
	}
	return 0;
}