#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<set>
#include<stdlib.h>
#include<string>
#include<utility>
#include<stack>
using namespace std;

int main(){
	string a,b;
	cin>>a>>b;
	int al=a.size();
	int bl=b.size();
	int x,y;
	int tmp=1;
	for(int i=0;i<al&&tmp;i++){
		for(int j=0;j<bl&&tmp;j++){
			if(a[i]==b[j]) {x=i;y=j;tmp=0;}
		}
	}
	for(int i=0;i<bl;i++){
		if(i==y){
			cout<<a<<endl;
			continue;
		}
		for(int j=0;j<al;j++){
			if(j==x){
				printf("%c",b[i]);
			}else printf(".");
		}
		puts("");
	}
	return 0;
}