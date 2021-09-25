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

int h,m;

int main(){
	cin>>h>>m;
	int x=h*60+m;
	x-=45;
	if(x<0) x+=1440;
	cout<<x/60<<' '<<x%60;
	return 0;
}