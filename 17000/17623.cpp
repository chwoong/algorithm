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
#include <cstdio>
#include <fstream>
using namespace std;

struct S{
	string s;
	bool operator<(const S&tmp)const{
		if(s.size()==tmp.s.size()) return s<tmp.s;
		else return s.size()<tmp.s.size();
	}
};
int t;
vector<S> v[1001];

int main(){
	v[1].push_back((S){"()"});
	v[2].push_back((S){"[]"});
	v[3].push_back((S){"{}"});
	for(int i=4;i<=1000;i++){
		v[i].push_back((S){v[i-1][0].s+"()"});
		v[i].push_back((S){"()"+v[i-1][0].s});
		
		v[i].push_back((S){v[i-2][0].s+"[]"});
		v[i].push_back((S){"[]"+v[i-2][0].s});
		
		v[i].push_back((S){v[i-3][0].s+"{}"});
		v[i].push_back((S){"{}"+v[i-3][0].s});
		
		if(i%2==0) v[i].push_back((S){"("+v[i/2][0].s+")"});
		if(i%3==0) v[i].push_back((S){"["+v[i/3][0].s+"]"});
		if(i%5==0) v[i].push_back((S){"{"+v[i/5][0].s+"}"});
		sort(v[i].begin(),v[i].end());
	}
	cin>>t;
	while(t--){
		int n;
		scanf("%d",&n);
		string x=v[n][0].s;
		int len=x.size();
		for(int i=0;i<len;i++){
			if(x[i]=='{') printf("[");
			else if(x[i]=='}') printf("]");
			else if(x[i]=='[') printf("{");
			else if(x[i]==']') printf("}");
			else printf("%c",x[i]);
		}
		puts("");
	}
	return 0;
}