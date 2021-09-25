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

int n,m;
string arr[1000];
string brr[1000];
int ans=0;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		arr[i]=s;
	}
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		brr[i]=s;
	}
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			for(int k=j+1;k<m;k++){
				set<string> s;
				for(int p=0;p<n;p++){
					string x="";
					x+=arr[p][i];
					x+=arr[p][j];
					x+=arr[p][k];
					s.insert(x);
				}
				bool flag=true;
				for(int p=0;p<n;p++){
					string x="";
					x+=brr[p][i];
					x+=brr[p][j];
					x+=brr[p][k];
					if(s.count(x)) flag=false;
				}
				if(flag) ans++; 
			}
		}
	}
	cout<<ans;
	return 0;
}