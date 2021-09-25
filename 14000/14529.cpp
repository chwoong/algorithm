#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<cmath>
#include<time.h>
using namespace std;

int n;
int m[20][20];
struct S{
	int x1,x2,y1,y2;
};

bool visited[500];
int num[26];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool ans[50000];

vector<S> v;

void dfs(int i,int j,int x1,int x2,int y1,int y2){
	visited[i*20+j]=true;
	for(int t=0;t<4;t++){
		int ni=i+dx[t];
		int nj=j+dy[t];
		if(ni>=x1 && ni<=x2 && nj>=y1 && nj<=y2 && !visited[ni*20+nj] && m[i][j]==m[ni][nj])
			dfs(ni,nj,x1,x2,y1,y2);
	}
}

//해당 직사각형이 pcl인지 확인함
bool f(int x1,int x2,int y1,int y2){
	memset(visited,false,sizeof(visited));
	memset(num,0,sizeof(num));
	for(int i=x1;i<=x2;i++){
		for(int j=y1;j<=y2;j++){
			int here=i*20+j;
			if(visited[here]) continue;
			num[m[i][j]-'A']++;
			dfs(i,j,x1,x2,y1,y2);
		}
	}
	int a=0;
	int b=0;
	for(int i=0;i<26;i++){
		if(num[i]==1) a++;
		else if(num[i]>=2) b++;
	}
	if(a==1 && b==1) return true;
	return false;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<n;j++){
			m[i][j]=s[j];
		}
	}
	for(int x1=0;x1<n;x1++){
		for(int x2=x1;x2<n;x2++){
			for(int y1=0;y1<n;y1++){
				for(int y2=y1;y2<n;y2++){
					if(f(x1,x2,y1,y2)){
						v.push_back((S){x1,x2,y1,y2});
					}
				}
			}
		}
	}
	memset(ans,true,sizeof(ans));
	int len=v.size();
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			//i가 j에 포함되는지 확인
			if(i!=j && v[i].x1>=v[j].x1 && v[i].x2<=v[j].x2 && v[i].y1>=v[j].y1 && v[i].y2<=v[j].y2)
				ans[i]=false;
		}
	}
	int res=0;
	for(int i=0;i<len;i++){
		if(ans[i]) res++;
	}
	cout<<res;
	return 0;
}