#include <iostream>
#include <algorithm>

using namespace std;

int dist[16][16]={0};
int N;
#define INF 20000000;
/* dp[i][visited]: 현재 방문 도시가 i이고 현재까지 방문한 도시 정보가 vistied(비트마스킹) 이때 0으로 돌아오는 최단거리*/
int dp[16][1<<16]={0,};

int tsp(int here,int visited){
	int &ret = dp[here][visited];
	if(ret!=0) return ret;
	if(visited == (1<<N) -1 && dist[here][0]) return dist[here][0];
	else if(visited == (1<<N) -1 && dist[here][0]==0) return -1;
	ret = INF;
	/* 다음 방문 결정 */
	for(int i=1;i<N;i++){
		/* i번째 도시를 방문 했으면 */
		if(visited & (1<<i)) continue;
		/*갈 길이 없으면*/
		if(dist[here][i]==0) continue;
		int x=tsp(i,visited|(1<<i));
		if(x!=-1) ret = min(ret,x+dist[here][i]);
	}
	return ret;
}

int main()
{
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> dist[i][j];
        }
    }
	cout<< tsp(0,1);
    return 0;
}