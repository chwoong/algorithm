#include<iostream>
#include<stdio.h>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int N;
/* 소를 저장하는 map를 최적화하고 psum을 저장할 거임 */
int map[1001][1001]={0,};
/*psum*/
int psum[1001][1001];

vector<int> coordx;
vector<int> coordy;
vector<pair<int,int>> cows;

int main(){
	cin >> N;
	int x,y;
	for(int i=0;i<N;i++){
		scanf("%d %d",&x,&y);
		cows.push_back(make_pair(x,y));
		coordx.push_back(x);
		coordy.push_back(y);
	}
	sort(coordx.begin(),coordx.end());
	sort(coordy.begin(),coordy.end());
	for(int i=0;i<N;i++){
		x=cows[i].first;
		y=cows[i].second;
		for(int j=0;j<N;j++){
			if(x==coordx[j]){x=j; break;}
		}
		for(int j=0;j<N;j++){
			if(y==coordy[j]){y=j;break;}
		}
		/* 0행과 0열은 psum계산시 용이하도록 남겨둔다 */
		map[x+1][y+1]=1;
	}
	/* psum계산 */
	for(int i=0;i<=N;i++){
		psum[0][i]=0;
		psum[i][0]=0;
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			psum[i][j] = psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+map[i][j];
		}
	}
	int ret=N;
	/*mincow계산*/
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			int a,b,c,d;
			a=psum[i][j];
			b=psum[i][N]-a;
			c=psum[N][j]-a;
			d=N-a-b-c;
			int m=max(a,b);
			m=max(m,c);
			m=max(m,d);
			ret=min(ret,m);
		}
	}
	cout<<ret;
	return 0;
}