#include<iostream>
#include<queue>
#include<vector>


using namespace std;

int test;
int w,h;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char map[1000][1000];
int visited[1000][1000];
int howlong(){
	cin >> w>>h;
	queue<pair<int,int>> man;
	queue<pair<int,int>> fire;
	for(int j=0;j<h;j++){
		for(int k=0;k<w;k++){
			cin >> map[j][k];
			visited[j][k]=-1;
			if(map[j][k]=='@') {
				man.push(make_pair(j,k));
				map[j][k]='.';
			}
			if(map[j][k]=='*') fire.push(make_pair(j,k));
		}
	}
	pair<int,int> m=man.front();
	if(m.first==0 || m.first==h-1 || m.second==0 || m.second==w-1) return 0;
	int dist=0;
	while(!man.empty()){
		int fnum=fire.size();
		/* 불이 각 파원으로부터 번짐, 그 정보를 map에 저장 */
		for(int i=0;i<fnum;i++){
			pair<int,int> danger = fire.front();
			fire.pop();
			int x=danger.first;
			int y=danger.second;
			/* 불에 대한 bfs*/
			for(int t=0;t<4;t++){
				int nx=x+dx[t];
				int ny=y+dy[t];
				if(nx>=0 && nx<h && ny>=0 && ny<w && map[nx][ny]!='#'){
					if(map[nx][ny]!='*') fire.push(make_pair(nx,ny));
					map[nx][ny]='*';
				}
			}
		}
		
		/* 불 번짐 정보 저장 후 man이 움직일 수 있는 가능성 저장 */
		int temp=man.size();
		for(int p=0;p<temp;p++){
			pair<int,int> here = man.front();
			man.pop();
			int hx=here.first;
			int hy=here.second;
			for(int t=0;t<4;t++){
					int nx=hx+dx[t];
					int ny=hy+dy[t];
					if(nx>=0 && nx<h && ny>=0 && ny<w && map[nx][ny]=='.' && visited[nx][ny]==-1){
						visited[nx][ny]=0;
						man.push(make_pair(nx,ny));
					}
					if((nx==0 || nx==h-1 || ny==0 || ny==w-1) && map[nx][ny]=='.'){
						return dist+1;
					}
			}
		}
		dist++;	
	}
	return -1;
}

int main(){
	cin >>test;
	for(int l=0;l<test;l++){
		int d=howlong();
		if(d>=0) cout<< d+1<<endl;
		else cout<< "IMPOSSIBLE"<<endl;
	}
	
	
	return 0;
}