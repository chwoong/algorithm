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

int square(int i){
	return i*i;
}
int main(){
	int g;
	cin>>g;
	//�ڿ��� a<b�� ���� b^2-a^2=g�� �� b�� ����ϴ� �����̴�.
	//b�� �ִ��� (g+2)/2, ���������� g/2+3
	int h=g/2+3;
	int s=1,e=1;
	int ans=0;
	int val=0;
	while(1){
		if(val>=g) val=(val+square(s)-square(++s));
		else if(e==h) break;
		else if(val<g) val=(val-square(e)+square(++e));
		if(val==g) {printf("%d\n",e);ans++;}
	}
	if(ans==0) cout<<-1;
	return 0;
}