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
#include<cmath>
using namespace std;

int N,K;
struct node{
	int n;
	node* prev;
	node* next;
}jose[5001];



int main(){
	cin>>N>>K;
	for(int i=0;i<N;i++){
		jose[i].n=i;
		jose[i].next=&jose[(i+1)%N];
		jose[i].prev=&jose[(i-1+N)%N];
	}
	vector<int> permu;
	node* curr=&jose[0];
	while(N){
		for(int i=0;i<K-1;i++){
			curr=curr->next;
		}
		/* 조세퍼스 순열에 넣고 */
		permu.push_back((curr->n)+1);
		/* node 삭제 */
		(curr->prev)->next = curr->next;
		(curr->next)->prev = curr->prev;
		curr=curr->next;
		N--;
	}
	cout<<"<";
	for(int i=0;i<permu.size();i++){
		if(permu.size()==1) {cout<<permu[0];break;}
		else if(i==0) cout<<permu[0];
		else cout<<", "<<permu[i];
	}
	cout<<">";
	return 0;
}