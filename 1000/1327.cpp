#include<iostream>
#include <stdio.h>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

int N,K;
string start="",finish="";
#define INF 100000000
/* 해당 state의 게임 끝내기 위한 최소 횟수 */
map<string,bool> c;
queue<string> q;
int dist=0;
/* x라는 수를 앞에서부터 i번째~ (i+K-1)번째를 뒤집어서 반환 */
string reverse(string S){
	int len = S.length();
	string result = "";
	for(int i=len-1; i>=0; i--)
		result += S[i];
	return result;
}

int bfs(){
	while(!q.empty()){
		int size=q.size();
		for(int i=0;i<size;i++){
			string state=q.front();
			q.pop();
			if(state==finish) return dist;
			for(int j=0;j<=N-K;j++){
				string nstate=state.substr(0, j) + reverse(state.substr(j, K)) + state.substr(j+K, N-j-K);
				if(c.count(nstate)==0) {q.push(nstate); c[nstate]=true;}
			}
		}
		dist++;
	}
	return -1;
}

int main(){
	cin >> N >> K;
	int input;
	for(int i=0; i<N; i++){
		cin >> input;
		start += input+'0';
	}
	finish = start;
	sort(finish.begin(), finish.end());
	q.push(start);
	c[start]=true;
	cout<<bfs();
	
	return 0;
}