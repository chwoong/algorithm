#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n;
int arr[25][25];
bool visited[25][25];
int mx[4]={1,0,-1,0};
int my[4]={0,1,0,-1};

int dfs(int x,int y){
	int size=1;
	visited[x][y]=true;
	for(int i=0;i<4;i++){
		int nx=x+mx[i];
		int ny=y+my[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<n&&!visited[nx][ny]&&arr[nx][ny]){
			size+=dfs(nx,ny);
		}
	}
	return size;
}

int main(){
	
	cin >> n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<n;j++){
			arr[i][j]=s[j]-'0';
			visited[i][j]=false;
		}
	}
	
	vector<int> apart;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int num;
			if(arr[i][j]&&!visited[i][j]){
				num=dfs(i,j);
				apart.push_back(num);
			}
		}
	}
	
	sort(apart.begin(),apart.end());
	cout<< apart.size()<<endl;
	for(int nb:apart)
		cout << nb <<endl;
	
	return 0;
}

