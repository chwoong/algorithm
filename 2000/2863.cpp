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
using namespace std;

int main(){
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	double x;
	x=a/c+b/d;
	int i=0;
	if(x<(c/d+a/b)) {x=(c/d+a/b); i=1;}
	if(x<(d/b+c/a)) {x=(d/b+c/a); i=2;}
	if(x<(b/a+d/c)) {x=(b/a+d/c); i=3;}
	cout<<i;
	return 0;
}