#include <iostream>
#include <algorithm>

using namespace std;

int R,C;
char map[20][20];
bool alphabet[26]={false,};
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

int dfs(int i,int j){
	int ret=1;
	for(int k=0;k<4;k++){
		int nx=i+dx[k];
		int ny=j+dy[k];
		if(nx>=0 && nx<R && ny>=0 && ny<C && !alphabet[map[nx][ny]-'A']){
			alphabet[map[nx][ny]-'A']=true;
			ret= max(ret,1+dfs(nx,ny));
			alphabet[map[nx][ny]-'A']=false;
		}
	}
	return ret;
	
}

int main(){
	cin>>R>>C;
	for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
			cin >> map[i][j];
	
	alphabet[map[0][0]-'A']=true;
	cout << dfs(0,0);

	return 0;
}