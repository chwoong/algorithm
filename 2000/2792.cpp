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

#define MAX 1000000000
int N,M;
int arr[300000];
int main(){
	cin>>N>>M;
	for(int i=0;i<M;i++)
		scanf("%d",arr+i);
	int l=0;
	int h=MAX;
	while(l+1<h){
		int mid=(l+h)/2;
		long long num=0;
		for(int i=0;i<M;i++){
			num+=(arr[i]+mid-1)/mid;
		}
		//�ִ� �������� mid�϶� �ִ��� ���� ����鿡�� �����ַ��� ������
		//�׶��� n���� ũ�� mid�� �Ұ�����. �� ū mid�̾�� ��
		if(num>N) l=mid;
		else h=mid;
		//cout<<l<<" "<<h<<endl;
	}
	cout<<h;
}