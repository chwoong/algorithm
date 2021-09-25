#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>

using namespace std;
/* kks227님의 코드를 참조했음!!!! */
int k;
/* 중복된 것 허용 안하기 때문에 이득 */
set<int> s[9];

void express(int i){
	if(i==1) {
		s[1].insert(k);
		s[1].insert(-k);
		return;
	}
	express(i-1);
	int r=k;
	for(int j=0;j<i-1;j++){
		r=r*10+k;
	}
	s[i].insert(r);
	s[i].insert(-r);
	/* 사칙연산 */
	for(int a=1;a<=i/2;a++){
		for(set<int>::iterator iter=s[i-a].begin();iter!=s[i-a].end();iter++){
			int t=*iter;
			for(set<int>::iterator iter2=s[a].begin();iter2!=s[a].end();iter2++){
				int u=*iter2;
				if(u!=0) s[i].insert(t/u);
				s[i].insert(t+u);
				s[i].insert(t*u);
				s[i].insert(t-u);
				if(t!=0) s[i].insert(u/t);
				s[i].insert(u+t);
				s[i].insert(u*t);
				s[i].insert(u-t);
				}
			}
	}
	
}

int main(){
	cin>>k;
	express(8);
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		int tm=1;
		for(int j=1;j<9;j++){
			set<int>::iterator iter = s[j].find(x);
			if(iter!=s[j].end()) {cout<<j<<'\n'; tm=0; break;}
		}
		if(tm==1) {cout<<"NO"<<'\n';}
	}
	
	return 0;
}