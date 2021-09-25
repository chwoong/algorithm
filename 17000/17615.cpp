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
string s;
int red,blue;
int ans;
int main(){
	cin>>n;
	cin>>s;
	ans=n;
	for(int i=0;i<n;i++){
		if(s[i]=='R') red++;
	}
	blue=n-red;
	int i=0;
	while(i<n-1){
		if(s[i]==s[i+1]) i++;
		else break;
	}
	i++;
	if(s[0]=='R') ans=min(ans,red-i);
	else ans=min(ans,blue-i);
	i=0;
	while(i<n-1){
		if(s[n-1-i]==s[n-2-i]) i++;
		else break;
	}
	i++;
	if(s[n-1]=='R') ans=min(ans,red-i);
	else ans=min(ans,blue-i);
	ans=min(ans,red);
	ans=min(ans,blue);
	cout<<ans;
	return 0;
}