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
		//ȸ������
		string rev=s;
		reverse(rev.begin(),rev.end());
		if(s==rev) {puts("0"); continue;}
		//���� ȸ������
		int len=s.size();
		bool tmp=false;
		int st=0;
		int fi=len-1;
		while(st<=fi){
			if(s[st]==s[fi]) {st++; fi--;}
			else break;
		}
		//st~fi������ ������ ����ȸ������ Ȯ��
		//�̶� st�� fi�� �ٸ���
		//st�� �������� ���� fi�� ������������ ��
		string k=s.substr(st+1,fi-st);
		//k�� ȸ���ΰ�?
		string r=k;
		reverse(r.begin(),r.end());
		if(r==k) {puts("1");continue;}
		k=s.substr(st,fi-st);
		//k�� ȸ���ΰ�?
		r=k;
		reverse(r.begin(),r.end());
		if(r==k) puts("1");
		else puts("2");
	}
	return 0;
}