#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>
#include<cmath>

using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	a>b? cout<<">": (a==b ? cout<<"==" : cout<<"<");
	return 0;
}