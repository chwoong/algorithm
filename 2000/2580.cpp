#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int map[9][9];
vector<pair<int,int>>zeros;

void dfs(int n){
	
	/* zero[n]을 p로 채울 수 있나?*/
	int x=zeros[n].first;
	int y=zeros[n].second;
	for(int p=1;p<=9;p++){
		int tmp=1;
		/*같은 열*/
		for(int c=0;c<9;c++){
			if(map[c][y]==p) {tmp=0;break;}
		}
		/*같은 행*/
		if(tmp==1)
		for(int r=0;r<9;r++){
			if(map[x][r]==p) {tmp=0;break;}
		}
		/*같은 사각형*/
		if(tmp==1){
			int sx=x-(x%3);
			int sy=y-(y%3);
			for(int i=sx;i<sx+3&&tmp==1;i++){
				for(int j=sy;j<sy+3;j++){
					if(map[i][j]==p) {tmp=0;break;}
				}
			}
		}
		if(tmp==1){
			map[x][y]=p;
			if(n==zeros.size()-1){
				for(int i=0;i<9;i++){
					for(int j=0;j<9;j++){
					cout<<map[i][j]<<" ";
				}
				cout<<endl;
				}
				return;
			}
			dfs(n+1);
			map[x][y]=0;
		}
	}
	return;
}

int main(){
	
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>map[i][j];
			if(map[i][j]==0){
				zeros.push_back(make_pair(i,j));
			}
		}
	}
	dfs(0);
	
	return 0;
}