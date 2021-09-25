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

int main(){
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(i==0) cout<<s[i];
		else if(s[i]=='-') cout<<s[i+1];
	}
	return 0;
}