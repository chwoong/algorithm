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

int N,K;

int main(){
	cin>>N>>K;
	vector<int> order;
	for(int i=0;i<K;i++){
		int x;
		cin>>x;
		order.push_back(x);
	}
	/*���� ����ϰ� �ִ� ���� ����*/
	int l=0;
	/*���� ������� �����ǰ ���� */
	set<int> use;
	/*�÷��� ���� Ƚ��*/
	int ans=0;
	for(int i=0;i<K;i++){
		/* ���� ����ϴ� �����ǰ */
		int here=order[i];
		if(l<N){
			set<int>::iterator it=use.find(here);
			if(it==use.end()) {use.insert(here); l++;}
		}
		else if(l==N){
			set<int>::iterator it=use.find(here);
			if(it!=use.end()) continue;
			/*���� �����ǰ�̸�*/
			else{
				ans++;
				set<int>s(use);
				for(int j=i+1;j<K;j++){
					if(s.size()==1) break;
					else{
						set<int>::iterator iter=s.find(order[j]);
						if(iter!=s.end()) s.erase(*iter);
					}
				}
				/*s.begin()�� �ش��ϴ� ���Ҹ� �ٲ���*/
				use.erase(*s.begin());
				use.insert(here);
			}
		}		
	}
	cout<<ans;
	return 0;
}