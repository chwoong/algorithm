#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
using namespace std;

int a1,b1,a2,b2;
int c1,d1,c2,d2;

void f(){
	if(a2<c1 || c2<a1 || b2<d1 || d2<b1){
		cout<<"NULL";
		return;
	}else{
		if(c2==a1){
			printf((d1==b2 || d2==b1)?"POINT":"LINE"); return;
		}
		if(c1==a2){
			printf((d1==b2 || d2==b1)?"POINT":"LINE"); return;
		}
		if(b2==d1){
			printf((c1==a2 || c2==a1)?"POINT":"LINE"); return;
		}
		if(b1==d2){
			printf((c1==a2 || c2==a1)?"POINT":"LINE"); return;
		}
		cout<<"FACE"; 
		return;
	}
}

int main(){
	cin>>a1>>b1>>a2>>b2;
	cin>>c1>>d1>>c2>>d2;
	f();	
	return 0;
}