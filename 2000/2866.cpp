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

int r,c;
string arr[1000];
string brr[1000];
int main(){
	cin>>r>>c;
	for(int i=0;i<r;i++){
		string s;
		cin>>s;
		arr[i]=s;
	}
	for(int i=0;i<c;i++){
		string s="";
		for(int j=0;j<r;j++)
			s+=arr[j][i];
		brr[i]=s;
	}
	bool tmp=true;
	int ans=r;
	for(int i=1;i<r&&tmp;i++){
		set<string> s;
		s.insert(brr[0].substr(i));
		for(int j=1;j<c;j++){
			string x=brr[j].substr(i);
			if(s.count(x)) {tmp=false; break;}
			else s.insert(x);
		}
		if(!tmp) ans=i;
	}
	cout<<ans-1;
	return 0;
}