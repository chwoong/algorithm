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

int n;
vector<int> v;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	//�̺� Ž��(index=h�� ������ʹ� �� ����� ���ɼ��� ����)
	int l=-1;
	int h=n-1;
	while(l+1<h){
		int mid=(l+h)/2;
		//index=mid�� ����� ����� ���ɼ��� �ִ��� Ȯ������
		bool tmp=true;
		//mid��° ����� ����
		int score=v[mid]+n;
		for(int i=0;i<n;i++){
			if(i<mid){
				if(score<v[i]+n-1-i){
					tmp=false;
					break;
				}
			}
			else if(i>mid){
				if(score<v[i]+n-i){
					tmp=false;
					break;
				}
			} 
		}
		if(tmp) h=mid;
		else l=mid;
	}
	cout<<n-h;
	return 0;
}