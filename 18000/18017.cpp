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
	double c=299792458;
	double a,b;
	cin>>a>>b;
	printf("%f",(a+b)/((double)1+(a/c)*(b/c)));
	return 0;
}