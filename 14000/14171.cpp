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
multiset<int> adj[676];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		char c[20];
		char s[20];
		scanf("%s",c);
		scanf("%s",s);
		int city=(c[0]-'A')*26+c[1]-'A';
		int state=(s[0]-'A')*26+s[1]-'A';
		if(city!=state) adj[city].insert(state);
	}
	int ans=0;
	for(int i=0;i<676;i++){
		for(multiset<int>::iterator it=adj[i].begin();it!=adj[i].end();it++){
			ans+=adj[*it].count(i);
		}
	}
	cout<<ans/2;
	return 0;
}