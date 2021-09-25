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

int n,m,k;
int main(){
	cin>>n>>m>>k;
	int team;
	if(n>m*2) team=m;
	else team=n/2;
	int x=n+m-team*3;
	k-=x;
	int a;
	if(k>=0)a=(k+2)/3;
	else a=0;
	cout<<team-a;
	return 0;
}