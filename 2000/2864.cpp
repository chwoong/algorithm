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

int a,b;
int main(){
	cin>>a>>b;
	int m=0;
	int t=a;
	int cnt=1;
	while(t){
		if(t%10==6) m+=5*cnt;
		else m+=(t%10)*cnt;
		cnt*=10;
		t/=10;
	}
	t=b;
	cnt=1;
	while(t){
		if(t%10==6) m+=5*cnt;
		else m+=(t%10)*cnt;
		cnt*=10;
		t/=10;
	}
	cout<<m;
	cout<<' ';
	m=0;
	t=a;
	cnt=1;
	while(t){
		if(t%10==5) m+=6*cnt;
		else m+=(t%10)*cnt;
		cnt*=10;
		t/=10;
	}
	t=b;
	cnt=1;
	while(t){
		if(t%10==5) m+=6*cnt;
		else m+=(t%10)*cnt;
		cnt*=10;
		t/=10;
	}
	cout<<m;
	return 0;
}