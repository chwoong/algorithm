#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

/*arr[i]: �������� ǥ�� �� i�ڸ��� ���� �� ��ģ���� ����*/
long long arr[90];
/*sum[i]: �������� ǥ�� �� i�ڸ� ������ ���� �� ��ģ���� ����*/
long long sum[90];
/*���� ���ڸ����ΰ�*/
int digit=2;
string solve(long long k,int i){
	if(i==0) return "";
	if(k==0) {string s; return s.assign(i,'0');}
	if(k==1 && i==1) return "1";
	if(k>=(sum[i-1]+1)) return "10"+solve(k-1-sum[i-1],i-2);
	else return "0"+solve(k,i-1);
}

int main(){
	long long K;
	cin>>K;
	if(K==1) {cout<< "1"; return 0;}
	if(K==2) {cout<<"10"; return 0;}
	/*�ϴ� arr�� �������*/
	arr[1]=1;sum[1]=1;
	arr[2]=1;sum[2]=2;
	for(int i=3;i<90;i++){
		arr[i]=arr[i-1]+arr[i-2];
		sum[i]=sum[i-1]+arr[i];
		digit++;
		if(sum[i]>=K) break;
	}
	cout<<"10"+solve(K-1-sum[digit-1],digit-2);
}