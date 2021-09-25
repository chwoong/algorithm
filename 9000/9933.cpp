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

set<string> pass;
int main(){
	int n;
	cin>>n;
	string ans;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		pass.insert(s);
		reverse(s.begin(),s.end());
		if(pass.count(s)){ans=s; break;}
	}
	int x=ans.size();
	cout<<x<<' ';
	printf("%c",ans[x/2]);
	return 0;
}