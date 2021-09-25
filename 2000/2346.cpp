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

class Node{
	public:
	int val;
	int num;
	Node* prev;
	Node* next;
};

int main(){
	int n;
	cin>>n;
	Node *node=new Node[n+1];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		node[i].val=x;
		node[i].num=i;
		node[i].next=&node[i%n+1];
		node[i].prev=&node[i==1?n:i-1];
	}
	Node* p=&node[1];
	while(1){
		cout<<(p->num)<<" ";
		int step=p->val;
		if(p->next==p) break;
		p->prev->next=p->next;
		p->next->prev=p->prev;
		if(step>0)
			for(int i=0;i<step;i++)
				p=p->next;
		else
			for(int i=0;i<-step;i++)
				p=p->prev;
	}
	delete[]node;
	return 0;
}