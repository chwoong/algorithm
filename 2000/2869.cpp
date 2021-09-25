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

long long a,b,v;
int main(){
	cin>>a>>b>>v;
	cout<<(v+a-2ll*b-1ll)/(a-b);
}