#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int ans=10000000;
int a,c,g,t;
int main(){
	string s1;
	string s2;
	cin>>s1;
	cin>>s2;
	int n=s1.size();
	int m=s2.size();
	cin>>a>>c>>g>>t;
	for(int i=0;i<n;i++){
		//i부터 확인
		int tmp=i;
		int x=0;
		for(int j=0;j<m;j++){
			if(s2[j]==s1[tmp]){tmp++;}
			else{
				if(s2[j]=='A') x+=a;
				else if(s2[j]=='C') x+=c;
				else if(s2[j]=='G') x+=g;
				else if(s2[j]=='T') x+=t;
			}
		}
		ans=min(ans,x);
	}
	cout<<ans;
	return 0; 
}