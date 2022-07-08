#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int n,m;
//v[i]: i��° ������ ���ҵ�
set <string> v[25];
//�����̾� �׷� : ������ ���׶�̸� �� ������ ���� �ִ� ������� ��������.
//���׶�̰� ���ļ� �������� ����� �Ұ����� ����̴�.
//a������ b������ ���׶�̰� ��ġ���� Ȯ���ϱ� ���ؼ���
//25���� ����� �з� ������ ���� a,b�� ���� �� �ִ� ���(1��)
//a���� �� �ִ� ���(2��), b���� �� �ִ� ���(3��)
//1,2,3���� ��찡 ��� �־�� �ȴ�.

set<string> s1;
vector<string> all;
bool intersect(int a0,int b0){
	int ab(0),a(0),b(0);
	for(int i=0;i<n;i++){
		bool hasa=false;
		bool hasb=false;
		if(v[i].count(all[a0])) hasa=true;
		if(v[i].count(all[b0])) hasb=true;
		if(hasa&&hasb) ab++;
		else if(hasa) a++;
		else if(hasb) b++;
	}
	return ab&&a&&b;
}
int main(){
	cin>>n;
	for(int p=0;p<n;p++){
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
			string s;
			cin>>s;
			v[p].insert(s);
			s1.insert(s);
		}
	}
	m=s1.size();
	for(set<string>::iterator it=s1.begin();it!=s1.end();it++){
		all.push_back(*it);
	}
	bool ans=true;
	for(int i=0;i<m-1;i++){
		for(int j=i+1;j<m;j++){
			//i,j������ ���� �������� �����ϴ��� Ȯ������.
			if(intersect(i,j)) ans=false;
		}
	}
	cout<<(ans?"yes":"no");
	return 0;
}