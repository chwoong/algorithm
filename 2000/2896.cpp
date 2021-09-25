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

double a,b,c;
double i,j,k;
int main(){
	cin>>a>>b>>c;
	cin>>i>>j>>k;
	double r=500;
	r=min(r,a/i);
	r=min(r,b/j);
	r=min(r,c/k);
	printf("%f %f %f",a-r*i,b-r*j,c-r*k);
	return 0;
}