#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool visited[51]={0,};
int ordered[51];
int num;
int tmp=1;

/*������ ���� �� ����, s�� ũ��*/
void solve(string s, int n,int size){
	if(n==0 && size==0 && tmp){
		for(int i=0;i<num;i++)
			printf("%d ",ordered[i]);
		tmp=0;
		return;
	}
	/*������ num-n�̴�*/
	//�� �տ� �� ĭ�� ������ �κ��� ���
	if(size>0 && s[0]>'0' && tmp){
		int x=s[0]-'0';
		if(!visited[x]&& x<=num){
			visited[x]=true;
			ordered[num-n]=x;
			solve(s.substr(1),n-1,size-1);
			visited[x]=false;
		}
	}
	//�� ���� �� ĭ�� ������ �κ��� ���
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
	/*����� ���� ����*/
	int len=s.size();
	if(len<=9) num=len;
	else num=9+(len-9)/2;
	/*bfs*/
	solve(s,num,len);
	return 0;
}