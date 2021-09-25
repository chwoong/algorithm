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

int n;
string s;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s[0]=='1') cout<<'.';
		else cout<<'-';
	}
	return 0;
}