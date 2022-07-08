#include <iostream>
#include <algorithm>

using namespace std;

int dist[16][16]={0};
int N;
#define INF 20000000;
/* dp[i][visited]: ���� �湮 ���ð� i�̰� ������� �湮�� ���� ������ vistied(��Ʈ����ŷ) �̶� 0���� ���ƿ��� �ִܰŸ�*/
int dp[16][1<<16]={0,};

int tsp(int here,int visited){
	int &ret = dp[here][visited];
	if(ret!=0) return ret;
	if(visited == (1<<N) -1 && dist[here][0]) return dist[here][0];
	else if(visited == (1<<N) -1 && dist[here][0]==0) return -1;
	ret = INF;
	/* ���� �湮 ���� */
	for(int i=1;i<N;i++){
		/* i��° ���ø� �湮 ������ */
		if(visited & (1<<i)) continue;
		/*�� ���� ������*/
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