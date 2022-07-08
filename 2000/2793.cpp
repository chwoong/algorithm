#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<set>
#include<stdlib.h>
#include<string>
#include<utility>
#include<stack>
using namespace std;

long long a,b;
//x[i]: lcm of 2,3,...,(2^i-1)
//y[i]: 2*x[i]
//x[i]+y[i]*k: ¦�� �� 2^i �÷� ���ϴ� �� ����
long long x[3];
long long y[3];

//�� �� a,b�� gcd ���ϱ�
long long gcd(long long i,long long j){
	if(i<j) swap(i,j);
	while(j!=0){
		long long tmp=j;
		j=i%j;
		i=tmp;
	}
	return i;
}
//2,3,...(2^i-1)������ lcm
long long lcm(int i){
	long long l=6;
	int t=i;
	int m=1;
	while(t--)
		m*=2;
	for(int k=2;k<m;k++){
		l*=((long long)k/gcd(l,k));
	}
	return l;
}
//strength(1)+...+strength(i)
long long solve(long long i){
	if(i==2) return 0;
	long long num=0;
	//�ϴ� 3�̻��� Ȧ���� ��� ���̰� 2�̴�.
	//Ȧ�� ����
	long long odd=(i+1)/2-1;
	num+=(long long)2*odd;
	//¦�� ��
	//x[i]+y[i]*k���� ���� ���̰� 4�̴�.(�� �ܿ��� 3)
	long long p=0;
	for(int j=0;j<4;j++){
		if(i>=x[j]) p+=((i-x[j])/y[j]+1);
	}
	long long even=i/2-1;
	num+=(even-p)*(long long)3+p*(long long)4;
	return num;
}
int main(){
	cin>>a>>b;
	x[0]=6; y[0]=12;
	x[1]=420; y[1]=840;
	x[2]=360360; y[2]=720720;
	x[3]=72201776446800;
	y[3]=144403552893600;
	printf("%lld",solve(b)-solve(a-1));
	return 0;
}