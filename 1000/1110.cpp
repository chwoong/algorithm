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
	int n,m,x;
	cin>>n;
	m=n;	
	int cycle=0;
	do{
		x=n/10+n%10;
		n=(n%10)*10+x%10;
		cycle++;
	}while(m!=n);
	cout<< cycle;
	return 0;
}