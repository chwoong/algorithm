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

set<vector<int> >s;
string a,b;
int n,m;
vector<int> v(26,0);
int ans=0;
int main(){
	cin>>a;
	cin>>b;
	n=a.size();
	m=b.size();
	int len=min(n,m);
	//���� i�� ���� ������ ���� ������ �ִ��� Ȯ������
	for(int i=1;i<=len;i++){
		for(int x=0;x<26;x++)
			v[x]=0;
		s.clear();
		for(int j=0;j<i;j++){
			v[a[j]-'a']++;
		}
		s.insert(v);
		//a�� j��°���Ҹ� �߰�����.(�翬�� j-i��° ���� ����)
		for(int j=i;j<n;j++){
			v[a[j]-'a']++;
			v[a[j-i]-'a']--;
			s.insert(v);
		}
		//���� b�� �����鼭 ���� ���� ������ �ִ��� Ȯ��
		for(int x=0;x<26;x++)
			v[x]=0;
		for(int j=0;j<i;j++){
			v[b[j]-'a']++;
		}
		if(s.count(v)) {ans=max(ans,i); continue;}
		for(int j=i;j<m;j++){
			v[b[j]-'a']++;
			v[b[j-i]-'a']--;
			if(s.count(v)) {ans=max(ans,i); break;}
		}
	}
	cout<<ans;
	return 0;
}