#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main(){
	int r,c,a,b;
	cin>>r>>c>>a>>b;
	for(int i=0;i<r*a;i++){
		for(int j=0;j<c*b;j++){
			int x=i%(2*a);
			int y=j%(2*b);
			if((x<a && y<b) || (a<=x && b<=y) ) printf("X");
			else printf(".");
		}
		puts("");
	}
	return 0;
}