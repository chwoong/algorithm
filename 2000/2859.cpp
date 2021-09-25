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

int ta,tb;
int pa,pb;

int g(int a,int b){
	if(a>b) swap(a,b);
	while(a!=0){
		int t=a;
		a=b%a;
		b=t;
	}
	return b;
}

int main(){
	for(int i=0;i<4;i++){
		string s;
		cin>>s;
		int a=10*(s[0]-'0')+(s[1]-'0');
		int b=10*(s[3]-'0')+(s[4]-'0');
		int c=60*a+b;
		if(i==0) ta=c;
		else if(i==1) tb=c;
		else if(i==2) pa=c;
		else pb=c;
	}
	if(ta>tb) {swap(ta,tb); swap(pa,pb);}
	int c=tb-ta;
	//pa * x -pb * y = c
	int gcd=g(pa,pb);
	if(c%gcd!=0) {puts("Never"); return 0;}
	int ppa=pa/gcd;
	int ppb=pb/gcd;
	int cc=c/gcd;
	int x;
	for(int i=0;i<ppa;i++){
		if((cc+ppb*i)%ppa==0){
			x=i;
			break;
		}
	}
	x=tb+pb*x;
	int q=x/1440;
	int r=x%1440;
	q%=7;
	switch(q){
		case 0: {puts("Saturday");break;}
		case 1: {puts("Sunday");break;}
		case 2: {puts("Monday");break;}
		case 3: {puts("Tuesday");break;}
		case 4: {puts("Wednesday");break;}
		case 5: {puts("Thursday");break;}
		case 6: {puts("Friday");break;}
	}
	if(r/60<10) cout<<0<<r/60;
	else cout<<r/60;
	cout<<":";
	if(r%60<10) cout<<0<<r%60;
	else cout<<r%60;
	
	return 0;
}