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

int n;
int size=0;
int heap[100001]={0,};

void del_q(){
	int tmp=heap[size];
	heap[size]=0;
	size--;
	heap[1]=tmp;
	int i=1;
	while(i<=size){
		int a,b;
		if(i*2<=size) a=heap[i*2];
		else a=-1;
		if(i*2<size) b=heap[i*2+1];
		else b=-1;
		int j;
		if(a!=-1 && b!=-1){
			j=a>b?i*2:(i*2+1);
		}else if(a==-1 &&b!=-1){
			j=i*2+1;
		}else if(a!=-1 && b==-1){
			j=i*2;
		}else{
			break;
		}
		if(heap[j]>heap[i]){
			int y=heap[j];
			heap[j]=heap[i];
			heap[i]=y;
			i=j;
		}else{
			break;
		}
	}
}
void put_q(int x){
	size++;
	heap[size]=x;
	int i=size;
	if(i==1) return;
	while(i>=2){
		int j=i/2;
		int a=heap[j];
		if(a<heap[i]){
			int y=heap[j];
			heap[j]=heap[i];
			heap[i]=y;
			i=j;
		}else{
			break;
		}
	}
}

int main(){
	cin>>n;
	int x;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(x==0&&size==0) {
			cout<< 0 <<'\n';
		}else if(x==0){
			cout<<heap[1] << '\n';
			del_q();
		}else put_q(x);
	}
	return 0;
}