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
using namespace std;

int n;
int arr[300001];
int l[300001];
int r[300001];
long long ans=0;
stack<int> s;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	/*case 1*/
	//arr[i]�� �ִ밡 �Ǵ� �ִ� ����[l,r]�� l�� ���ϱ�
	//�� ����
	for(int i=0;i<n;i++){
		while(!s.empty()){
			if(arr[s.top()]<=arr[i]) s.pop();
			else break;
		}
		l[i]=(s.empty()?0:s.top()+1);
		s.push(i);
	}
	//arr[i]�� �ּҰ� �Ǵ� �ִ� ����[l,r]�� r�� ���ϱ�
	//�����ʺ��� ������ ���� ����
	while(!s.empty()) s.pop();
	for(int i=n-1;i>=0;i--){
		while(!s.empty()){
			if(arr[s.top()]<arr[i]) s.pop();
			else break;
		}
		r[i]=(s.empty()?n-1:s.top()-1);
		s.push(i);
	}
	for(int i=0;i<n;i++){
		ans+=(long long)arr[i]*(long long)(r[i]-i+1)*(long long)(i-l[i]+1);
	}
	
	/*case 2*/
	//arr[i]�� �ּҰ� �Ǵ� �ִ� ����[l,r]�� l�� ���ϱ�
	//�� ����
	while(!s.empty()) s.pop();
	for(int i=0;i<n;i++){
		while(!s.empty()){
			if(arr[s.top()]>=arr[i]) s.pop();
			else break;
		}
		l[i]=(s.empty()?0:s.top()+1);
		s.push(i);
	}
	//arr[i]�� �ּҰ� �Ǵ� �ִ� ����[l,r]�� r�� ���ϱ�
	//�����ʺ��� ������ ���� ����
	while(!s.empty()) s.pop();
	for(int i=n-1;i>=0;i--){
		while(!s.empty()){
			if(arr[s.top()]>arr[i]) s.pop();
			else break;
		}
		r[i]=(s.empty()?n-1:s.top()-1);
		s.push(i);
	}
	for(int i=0;i<n;i++){
		ans-=(long long)arr[i]*(long long)(r[i]-i+1)*(long long)(i-l[i]+1);
	}
	cout<<ans;
	return 0;
}