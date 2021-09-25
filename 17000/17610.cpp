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

int k;
set<int> s;
map<int,int> m;
int g[13];
int sum;
int main(){
	cin>>k;
	for(int i=0;i<k;i++){
		scanf("%d",g+i);
		sum+=g[i];
	}
	int l=1;
	for(int x=0;x<k;x++)
		l*=2;
	int a=l;
	while(--l){
		int p=0;
		for(int x=0;x<k;x++){
			if((l>>x)&1) p+=g[x];
		}
		m[l]=p;
		s.insert(p);
	}
	for(int i=1;i<a;i++){
		for(int j=i+1;j<a;j++){
			if((i&j)==0) s.insert(abs(m[i]-m[j]));
		}
	}
	if(s.count(0)) cout<<sum-s.size()+1;
	else cout<<sum-s.size();
	return 0;
}