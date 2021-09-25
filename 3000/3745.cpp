#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
using namespace std;

int main(){
	int N;
	while(scanf("%d",&N)!=EOF){
		vector<int> v;
		while(N--){
			int x;
			scanf("%d ",&x);
			if(v.empty()) v.push_back(x);
			if(v.back()<x) v.push_back(x);
			else *lower_bound(v.begin(),v.end(),x)=x;
		}
		printf("%d\n",(int)v.size());
	}
	return 0;
}