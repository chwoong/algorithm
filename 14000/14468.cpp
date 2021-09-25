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

string s;
int st[26];
int en[26];
int ans=0;
int main(){
	cin>>s;
	memset(st,-1,sizeof(st));
	memset(en,-1,sizeof(en));
	for(int i=0;i<52;i++){
		int a=s[i]-'A';
		if(st[a]==-1) st[a]=i;
		else en[a]=i;
	}
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			if(st[i]<st[j] && st[j]<en[i] && en[j]>en[i]) ans++;
			else if(st[j]<st[i] && st[i]<en[j] && en[j]<en[i]) ans++;
		}
	}
	cout<<ans/2;
	return 0;
}