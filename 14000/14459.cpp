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
int sz(1);
int a[100000];
int b[100000];
int s[100000]; //������ ���� ������ i ���� �������� ���°�� �ִ°�
int seg[400000];

void update(int pos,int val){
	pos+=sz;
	seg[pos]=val;
	for(pos/=2;pos>0;pos/=2)
		seg[pos]=max(seg[pos*2],seg[pos*2+1]);
}

int query(int l,int r){
	l+=sz;
	r+=sz;
	int ret=0;
	while(l<=r){
		if(l%2==1) ret=max(ret,seg[l++]);
		if(r%2==0) ret=max(ret,seg[r--]);
		l/=2; r/=2;
	}
	return ret;
}

int main(){
	cin>>n;
	while(sz<n) sz*=2;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		a[i]--;
	}
	for(int i=0;i<n;i++){
		scanf("%d",b+i);
		b[i]--;
		s[b[i]]=i;
	}
	//���� ���� i��° �������� ģ�� �ҵ� ���� ���������� ��Ī
	//�� �� segment tree�� �̿����ٵ� ���� [l,r]�� segment tree�� ��ȯ����
	//�� ���������� ��Ī�� �� �ִ� �ִ� Ⱦ�ܺ��� ���̴�.
	for(int i=0;i<n;i++){
		vector<int> f;
		f.clear();
		//j�� a[i]�� ģ��
		for(int j=max(0,a[i]-4);j<=min(n-1,a[i]+4);j++){
			f.push_back(s[j]);
		}
		sort(f.begin(),f.end());
		//i�� ģ���߿� ���� index�� �ִ� ģ������ ���� update
		int len=f.size();
		for(int k=len-1;k>=0;k--){
			//m���� ���� [0,v[k]-1] �� �ִ� Ⱦ�ܺ��� ����
			int m=query(0,f[k]-1);
			//f[k]���� m+1���� �����ؾ� �Ѵ�.
			update(f[k],m+1);
		}
	}
	cout<<query(0,n-1);
	return 0;
}