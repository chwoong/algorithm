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

int alphabet[26];
struct Node{
	int num;
	char val;
	Node* prev;
	Node* next;
};

int main(){
	int n,k;
	cin>>n>>k;
	memset(alphabet,-1,sizeof(alphabet));
	Node *node=new Node[n];
	for(int i=0;i<n;i++){
		node[i].num=i;
		node[i].val='?';
		node[i].next=&node[(i+1)%n];
		node[(i+1)%n].prev=&node[i];
	}
	Node* p=&node[0];
	int a;
	char b;
	scanf("%d %c",&a,&b);
	p->val=b;
	/*p���� ��������*/
	for(int i=1;i<k;i++){
		int step;
		char c;
		scanf("%d %c",&step,&c);
		for(int j=0;j<step%n;j++){
			p=p->next;
		}
		if(p->val=='?') {
			/*�̹� �� ���ڸ� !���*/
			if(alphabet[c-'A']==-1) {alphabet[c-'A']=p->num; p->val=c;}
			else {cout<<'!'; return 0;}
		}
		/*���� ���� ���� ���� �������� ����*/
		else {
			if(p->val!=c) {cout<<'!'; return 0;}
		}
	}
	while(n--){
		printf("%c",p->val);
		p=p->prev;
	}
	delete[]node;
	return 0;
}