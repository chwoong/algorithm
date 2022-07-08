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
int up[100010];
int u[100010];
int down[100010];
int d[100010];
int fen[100010];
long long ans;

void update(int pos,int val){
	while(pos<=n){
		fen[pos]+=val;
		pos+=(pos&-pos);
	}
}
int sum(int pos){
	int s=0;
	while(pos>0){
		s+=fen[pos];
		pos-=(pos&-pos);
	}
	return s;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",up+i);
		u[up[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		down[x]=i;
		d[i]=x;
	}
	//ó�� ���������� �� ���� ���ϱ� by fenwick tree
	for(int i=1;i<=n;i++){
		ans+=(sum(n)-sum(down[up[i]]));
		update(down[up[i]],1);
	}
	//�������� ��ĭ�� ������ �̵��ϸ鼭 ���������� ���� �� ���� ��ȭ�� ���캸��
	long long tmp=ans;
	long long res=ans;
	/*�� �����̵�*/
	for(int i=1;i<=n;i++){
		//i��°�� ���� ���������� �̵���
		tmp=tmp+(long long)(n-down[up[i]])-(long long)(down[up[i]]-1);
		res=min(tmp,res);
	}
	tmp=ans;
	/*�� �������̵�*/
	for(int i=1;i<=n;i++){
		//i��°�� ���� ���������� �̵���
		tmp=tmp+(long long)(n-u[d[i]])-(long long)(u[d[i]]-1);
		res=min(tmp,res);
	}
	cout<<res;
	return 0;
}