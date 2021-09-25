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
string arr[501];
string brr[501];

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
	int l0=-1;
	int hi=m;
	while(l0+1<hi){
		int mid=(l0+hi)/2;
		set<string> s;
		int a=0;
		bool f=false;
		for(int i=0;i<=m-mid;i++){
			bool flag=false;
			for(int j=0;j<n;j++){
				s.insert(arr[j].substr(i,mid));
			}
			for(int j=0;j<n;j++){
				if(s.count(brr[j].substr(i,mid))) flag=true;
			}
			if(flag) a++;
			s.clear();
		}
		//길이 l일때 불가능
		if(a==m-mid+1) f=true;
		if(f) l0=mid;
		else hi=mid;
	}
	cout<<hi;
	return 0;
}