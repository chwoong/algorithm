#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>

using namespace std;

int t,m,d;

int main(){
	cin >> t;
	for(int i=0;i<t;i++){
		/* �ʱ� ���� */
		int mid;
		int minsize=0,maxsize=0;
		priority_queue<int,vector<int>,greater<int> > pqmin;
		priority_queue<int,vector<int>,less<int> > pqmax;
		int num=0;
		scanf("%d\n",&m);
		printf("%d\n",(m+1)/2);
		
		/* ���� �Է� */
		for(int j=0;j<m;j++){
			num++;
			if(num%10) scanf("%d ",&d);
			else scanf("%d",&d);
			/* �Է°��� ���� pqmax, pqmin�з� */
			if(j==0){
				mid=d;
				printf("%d ",mid);
			}else{
				if(d>=mid) {pqmin.push(d);minsize++;}
				else {pqmax.push(d);maxsize++;}
			}
			/* Ȧ���� °���� mid ���� �� ��� */
			if(j>0 && j%2==0){
				//mid�� �������
				 if(minsize>maxsize){
					int tmp=mid;
					mid=pqmin.top();
					pqmax.push(tmp);
					pqmin.pop();
					minsize=maxsize=0;
				}else if(minsize<maxsize){
					int tmp=mid;
					mid=pqmax.top();
					pqmin.push(tmp);
					pqmax.pop();
					maxsize=minsize=0;
				}
				printf("%d ",mid);
				if(num%20==19) printf("\n");
			}
			
		}
		 printf("\n");
	}
	return 0;
}