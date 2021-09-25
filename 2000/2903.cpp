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

int n;
int main(){
	cin>>n;
	long long ans=2;
	while(n--){
		ans=ans*2-1;
	}
	cout<<ans*ans;
	return 0;
}