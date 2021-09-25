#include<iostream>
#include<queue>
#include <vector>
#include<utility>
#include<algorithm>

using namespace std;

int F,S,G,U,D;

int bfs(){
	queue<int> q;
	bool visited[1000001]={false,};
	int num[1000001]={0,};
	num[S]=0;
	visited[S]=true;
	q.push(S);
	if(S==G) return 0;
	while(!q.empty()){
		int here=q.front();
		q.pop();
		int next = here+U;
		if(next>=1 && next<=F && !visited[next]){
			visited[next]=true;
			q.push(next);
			num[next]=num[here]+1;
		}
		if(next==G) return num[next];
		next = here-D;
		if(next>=1 && next<=F && !visited[next]){
			visited[next]=true;
			q.push(next);
			num[next]=num[here]+1;
		}
		if(next==G) return num[next];
	}
	return -1;
}

int main(){
	cin >> F>>S>>G>>U>>D;
	int step=bfs();
	if(step>=0) cout << step;
	else cout<< "use the stairs";
	return 0;
}