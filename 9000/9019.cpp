#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<string.h>
#include<queue>
using namespace std;

bool visited[10001];
string v[10001];
string arr[4]={"D","S","L","R"};

int dslr(int x,int i){
	int l,r;
	switch(x){
		case 0://D
			return (2*i)%10000;
		case 1://S
			return (9999+i)%10000;
		case 2://L
			l=(10*i)/10000;
			return (10*i)%10000+l;
		case 3://R
			r=i%10;
			return i/10+1000*r;
	}
}

void bfs(int a,int b){
	queue <int> q;
	q.push(a);
	visited[a]=true;
	int p=1;
	while(!q.empty()&&p){
		int num=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int tmp=dslr(i,num);
			if(visited[tmp]==false) {
				v[tmp]=v[num]+arr[i];
				visited[tmp]=true;
				q.push(tmp);
			}
			if(tmp==b) {
				p=0;
				cout<<v[tmp]<<endl;
				break;
			}
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b;
		scanf("%d %d",&a,&b);
		memset(visited,false,sizeof(visited));
		for(int i=0;i<10000;i++)
			v[i]="";
		bfs(a,b);
	}
	return 0;
}