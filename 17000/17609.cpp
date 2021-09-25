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

int n;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		//회문인지
		string rev=s;
		reverse(rev.begin(),rev.end());
		if(s==rev) {puts("0"); continue;}
		//유사 회문인지
		int len=s.size();
		bool tmp=false;
		int st=0;
		int fi=len-1;
		while(st<=fi){
			if(s[st]==s[fi]) {st++; fi--;}
			else break;
		}
		//st~fi까지의 구문이 유사회문인지 확인
		//이때 st와 fi는 다르다
		//st를 제거했을 때와 fi를 제거했을때를 비교
		string k=s.substr(st+1,fi-st);
		//k가 회문인가?
		string r=k;
		reverse(r.begin(),r.end());
		if(r==k) {puts("1");continue;}
		k=s.substr(st,fi-st);
		//k가 회문인가?
		r=k;
		reverse(r.begin(),r.end());
		if(r==k) puts("1");
		else puts("2");
	}
	return 0;
}