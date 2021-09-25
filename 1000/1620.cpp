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

using namespace std;

int N,M;
map<string,int> m;
vector<string> m2;
int main(){
	cin >> N >> M;
	char c[21];
	string s;
	for(int i=0;i<N;i++){
		scanf("%s",c);
		s=c;
		m[s]=i+1;
		m2.push_back(s);
	}
	for(int i=0;i<M;i++){
		scanf("%s",c);
		s=c;
		if(s[0]>='A') printf("%d\n",m[s]);
		else printf("%s\n",m2[stoi(s)-1].c_str());
	}
	return 0;
}