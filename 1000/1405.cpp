#include<iostream>
#include<string.h>

using namespace std;

int N;

bool visited[28][28];
int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};
double p[4];
double dfs(int i,int j,int step){
	double ret=0;
	if(step==N) return 1.0;
	for(int t=0;t<4;t++){
		int nx=i+dx[t];
		int ny=j+dy[t];
		if(visited[nx][ny]==false){
			visited[nx][ny]=true;
			ret+=dfs(nx,ny,step+1)*p[t]/100.0;
			visited[nx][ny]=false;
		}
	}
	return ret;
}

int main(){
	cin >> N;
	for(int i=0;i<4;i++){
		cin >> p[i];
	}
	memset(&visited[0][0],false,sizeof(visited));
	visited[14][14]= true;
	cout.precision(11);
	cout<<dfs(14,14,0);
	return 0;
}