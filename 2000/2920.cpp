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
using namespace std;

int arr[8];
int a[8]={1,2,3,4,5,6,7,8};
int d[8]={8,7,6,5,4,3,2,1};
int main(){
	for(int i=0;i<8;i++)
		scanf("%d",arr+i);
	bool tmp=true;
	for(int i=0;i<8;i++)
		if(a[i]!=arr[i]) tmp=false;
	if(tmp) {cout<<"ascending";return 0;}
	tmp=true;
	for(int i=0;i<8;i++)
		if(d[i]!=arr[i]) tmp=false;
	if(tmp) cout<<"descending";
	else cout<<"mixed";
	return 0;
}