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
 

int main(){
	int a,b;
	cin>>a>>b;
	a+=(a%10-a/100)*99;
	b+=(b%10-b/100)*99;
	if(a<b) cout<<b;
	else cout<<a;
	return 0;
}