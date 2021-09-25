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

int main(){
	int t;
	cin>>t;
	//300 60 10
	int a=t/300;
	int b=(t-300*a)/60;
	int c=(t-300*a-60*b)/10;
	if(a*300+b*60+c*10!=t) puts("-1");
	else printf("%d %d %d",a,b,c);
	return 0;
}