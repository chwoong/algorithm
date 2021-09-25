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

typedef pair<int,int> P;
set<P> s;

int gcd(int i,int j){
	return j?gcd(j,i%j):i;
}

int main(){
	int d1,d2;
	cin>>d1>>d2;
	s.insert(P(0,0));
	for(int i=d1;i<=d2;i++){
		for(int x=1;x<i;x++){
			//기약분수 (x/i)를 set에 저장
			int g=gcd(x,i);
			s.insert(P(x/g,i/g));
 		}
	}
	cout<<s.size();
	return 0;
}