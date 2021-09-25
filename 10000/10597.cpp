#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool visited[51]={0,};
int ordered[51];
int num;
int tmp=1;

/*앞으로 남은 수 개수, s의 크기*/
void solve(string s, int n,int size){
	if(n==0 && size==0 && tmp){
		for(int i=0;i<num;i++)
			printf("%d ",ordered[i]);
		tmp=0;
		return;
	}
	/*순서는 num-n이다*/
	//맨 앞에 한 칸이 순열의 부분인 경우
	if(size>0 && s[0]>'0' && tmp){
		int x=s[0]-'0';
		if(!visited[x]&& x<=num){
			visited[x]=true;
			ordered[num-n]=x;
			solve(s.substr(1),n-1,size-1);
			visited[x]=false;
		}
	}
	//맨 앞의 두 칸이 순열의 부분인 경우
	if(size>1 && s[0]>'0' && tmp){
		int x=(s[0]-'0')*10+(s[1]-'0');
		if(!visited[x] && x<=num){
			visited[x]=true;
			ordered[num-n]=x;
			solve(s.substr(2),n-1,size-2);
			visited[x]=false;
		}
	}
}

int main(){
	string s;
	cin>>s;
	/*사용한 숫자 개수*/
	int len=s.size();
	if(len<=9) num=len;
	else num=9+(len-9)/2;
	/*bfs*/
	solve(s,num,len);
	return 0;
}