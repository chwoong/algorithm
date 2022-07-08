#include<iostream>
#include<queue>
#include<map>
#include <utility>
#include<stdio.h>

using namespace std;

/*state ��Ʈ����ŷ*/
/* 0 1 2
   3 4 5
   6 7 8
�� state�� long long ������ ����*/
int pos;
long long start=0;
long long finish=0;
int dist=0;

long long swap(int p,int d,long long s){
	//printf("p:%d d:%d\n",p,d);
	//printf("s: %llX\n",s);
	long long a= (s>>4*(p+d)) & 15ll;
	long long b= s>>(4*p) & 15ll;
	long long x=0;
	for(long long i=0;i<9;i++){
		if(i==p+d) x = x | (b<<(4*(p+d)));
		else if(i==p) x= x | (a<<(4*p));
		else x = x | (((s>>(4*i))&15ll)<<(4*i));
	}
	//printf("x: %llX\n",x);
	return x;
}

int bfs(){
	if(start==finish) return 0;
	/* bfs�� ����� queue (state,0�� ��ġ) */
	queue<pair<long long,int>>q;
	/* state�� �湮 ���θ� Ȯ���ϴ� map */
	map<long long,bool> c;
	
	q.push(make_pair(start,pos));
	c[start]=true;
	while(!q.empty()){
		int size=q.size();
		for(int k=0;k<size;k++){
		pair<long long,int> state = q.front();
		pair<long long,int> n_state;
		long long p=state.second;
		long long s=state.first;
		q.pop();
		/* 0�� �Ʒ� ���ڿ� swap�ϴ� bfs ����*/
		if(p<6){
			/* p��ġ�� p+3��ġ swap */
			n_state.first = swap(p,3,s);
			n_state.second = p+3;
			/* �湮�� ���� ������ */
			if(c.count(n_state.first)==0) {q.push(n_state); c[n_state.first]=true;}
		}
		if(n_state.first==finish) return dist+1;
		if(p>2){
			n_state.first = swap(p,-3,s);
			n_state.second = p-3;
			if(c.count(n_state.first)==0) {q.push(n_state); c[n_state.first]=true;}
		}
		if(n_state.first==finish) return dist+1;
		if(p%3!=2){
			n_state.first = swap(p,1,s);
			n_state.second = p+1;
			if(c.count(n_state.first)==0) {q.push(n_state); c[n_state.first]=true;}
		}
		if(n_state.first==finish) return dist+1;
		if(p%3!=0){
			n_state.first = swap(p,-1,s);
			n_state.second = p-1;
			if(c.count(n_state.first)==0) {q.push(n_state); c[n_state.first]=true;}
		}
		if(n_state.first==finish) return dist+1;
		}
		dist++;
	}
	return -1;
}



int main(){
	for(int i=0;i<9;i++){
		long long val;
		cin>> val;
		if(val==0) pos=i;
		start = start | (val<<(4*i));
	}
	for(long long i=1;i<9;i++){
		finish = finish | (i<<(4*(i-1)));
	}
	cout << bfs();
	
	return 0;
}