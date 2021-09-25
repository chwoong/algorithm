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
/* N의 자릿수*/
int digit=0;
/* N의 자릿수 중 0의 개수*/
int zeros=0;
/* bfs 깊이 */
int depth=0;
bool visited[1000001][11]={false,};
/*최댓값 저장*/
int tmp=0;

/* 10^i 반환 */
int calc(int i){
	int k=1;
	for(int j=0;j<i;j++)
		k*=10;
	return k;
}

int swap(int x,int i,int j){
	/* i번째 자릿수 */
	int ai=(x/calc(i))%10;
	int aj=(x/calc(j))%10;
	if(ai==0 && j==digit-1) return -1;
	return x+(aj-ai)*(calc(i)-calc(j));
}

void bfs(){
	queue<int> q;
	q.push(N);
	visited[N][0]=true;
	while(depth<K){
		int len=q.size();
		for(int p=0;p<len;p++){
			int x=q.front();
			q.pop();
			/* 교환 구현 */
			for(int i=0;i<digit-1;i++){
				for(int j=i+1;j<digit;j++){
					int y=swap(x,i,j);
					if(y!=-1 && visited[y][(depth+1)]==false){
						visited[y][(depth+1)]=true;
						if(depth+1==K) {tmp=max(tmp,y);}
						q.push(y);
					}
				}
			}
		}
		depth++;
	}
}

int main(){
	cin >> N >> K;
	if(N<10) {cout<<-1; return 0;}
	int i=N;
	while(i!=0){
		if(i%10==0) zeros++;
		i/=10;
		digit++;
	}
	/* K번 연산 못할 시  */
	if(digit==1 || (digit==2 && N%10==0)) {cout<<-1; return 0;}
	/* 연산이 가능하므로 bfs한다 */
	bfs();
	cout<<tmp;
	
	return 0;
}