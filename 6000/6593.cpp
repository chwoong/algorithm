#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

char map[30][30][30];
int dist[30][30][30];
bool visited[30][30][30];
int L,R,C;
int sx,sy,sz;
int fx,fy,fz;
int dx[6]={1,0,0,-1,0,0};
int dy[6]={0,1,0,0,-1,0};
int dz[6]={0,0,1,0,0,-1};

struct coord{
	int x,y,z;	
};

int bfs(){
	queue<coord> q;
	coord p1={sx,sy,sz};
	visited[sz][sy][sx]=true;
	dist[sz][sy][sx]=0;
	q.push(p1);
	while(!q.empty()){
		coord p=q.front();
		q.pop();
		for(int i=0;i<6;i++){
			int nx=p.x+dx[i];
			int ny=p.y+dy[i];
			int nz=p.z+dz[i];
			/*map[nz][ny][nx]=='E'¸¦ »©¸Ô¾î¼­ ÇÑ½Ã°£ °É¸²¤Ð¤Ð*/ 
			if(nx>=0&&nx<C&&ny>=0&&ny<R&&nz>=0&&nz<L&&!visited[nz][ny][nx]&&(map[nz][ny][nx]=='.'||map[nz][ny][nx]=='E')){
				dist[nz][ny][nx]=dist[p.z][p.y][p.x]+1;
				coord p2;
				p2.x=nx; p2.y=ny; p2.z=nz;
				q.push(p2);
				visited[nz][ny][nx]=true;
			}
			if(nx==fx&&ny==fy&&nz==fz) {return dist[fz][fy][fx];}
		}
	}
	return -1;
}


int main(){
	while(1){
		cin >> L >> R >> C;
		if(L+R+C==0) break;
		for(int i=0;i<L;i++)
			for(int j=0;j<R;j++)
				for(int k=0;k<C;k++){
					char c;
					cin >>c;
					map[i][j][k]=c;
					dist[i][j][k]=0;
					visited[i][j][k]=false;
					if(c=='S') {sz=i;sy=j;sx=k;}
					if(c=='E') {fz=i;fy=j;fx=k;}
				}
		int res=bfs();
		if(res>=0) cout<< "Escaped in " << res <<" minute(s)."<<endl;
		else cout<<"Trapped!"<<endl;
	}
}