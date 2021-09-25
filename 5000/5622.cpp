#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main(){
	string s;
	cin>>s;
	int len=s.size();
	int ans=0;
	for(int i=0;i<len;i++){
		int x=s[i]-'A';
		int y;
		if(x<=14) y=x/3;
		else if(15<=x&& x<=18) y=5;
		else if(19<=x&&x<=21) y=6;
		else y=7;
		y+=3;
		ans+=y;
	}
	cout<<ans;
	return 0;
}