#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int width,height,k;
int reg[100][100];
bool visited[100][100];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int dfs(int i,int j){
	visited[i][j]=true;
	int tmp=1;
	for(int t=0;t<4;t++){
		int nx=i+dx[t];
		int ny=j+dy[t];
		if(nx>=0 && nx<width && ny>=0 && ny<height && !visited[nx][ny] && !reg[nx][ny])
			tmp+=dfs(nx,ny);
	}
	return tmp;
}

int main(){
	cin >> height >> width >>k;

	fill(&reg[0][0],&reg[0][0]+sizeof(reg)/sizeof(int),0);
	fill(&visited[0][0],&visited[0][0]+sizeof(visited)/sizeof(bool),false);
	
	
	/* 직사각형 채웢진 곳에 1 저장 */
	for(int i=0;i<k;i++){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int n=x1;n<x2;n++){
			for(int m=y1;m<y2;m++){
				reg[n][m]=1;
			}
		}
		
	}
	vector <int> si;
	
	for(int i=0;i<width;i++){
		for(int j=0;j<height;j++){
			if(!visited[i][j] && !reg[i][j]) si.push_back(dfs(i,j));
		}
	}
	sort(si.begin(),si.end());
	cout << si.size()<<endl;
	for(int ele:si)
		cout << ele<< " ";
	
	return 0;
}
