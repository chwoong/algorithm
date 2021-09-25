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

int main(){
	cin>>s;
	int len=s.size();
	//끝에가 6이면 4로 바꿀 수 있다.
	if(len>=2 && s[len-2]=='V' && s[len-1]=='I'){
		s[len-2]='I';
		s[len-1]='V';
	}
	//시작이 LX이면 XL로 바꿀 수 있다.
	if(len>=2 && s[0]=='L' && s[1]=='X' && s[2]!='X'){
		s[0]='X';
		s[1]='L';
	}
	if(s=="XI" || s=="XXI" || s=="XXXI"){
		s[len-2]='I';
		s[len-1]='X';
	}
	if(s=="LXXI") s="XLIX";
	cout<<s;
	
	return 0;
}