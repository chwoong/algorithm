#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main(){
	int n,p;
	cin>>n>>p;
	int a=p/(n-1);
	if(p%(n-1)==0) cout<<p+a-1<<' '<<p+a;
	else cout<<p+a<<' '<<p+a;
	return 0; 
}