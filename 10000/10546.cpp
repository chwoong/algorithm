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

int n;
multiset<string> m;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		m.insert(s);
	}
	for(int i=0;i<n-1;i++){
		cin>>s;
		multiset<string>::iterator it=m.find(s);
		m.erase(it);
	}
	cout<<(*m.begin());
	return 0;
}