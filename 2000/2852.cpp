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
using namespace std;

int n;
//점수
int a,b;
//이기고 있던 초
int ta,tb;
int team[110];
int t[110];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",team+i);
		string s;
		cin>>s;
		t[i]=((s[0]-'0')*10+(s[1]-'0'))*60+((s[3]-'0')*10+(s[4]-'0'));
	}
	t[n+1]=2880;
	for(int i=0;i<=n;i++){
		if(a>b){
			ta+=(t[i+1]-t[i]);
		}else if(a<b){
			tb+=(t[i+1]-t[i]);
		}
		if(team[i+1]==1) a++;
		else if(team[i+1]==2) b++;
	}
	int x=ta/60;
	int y=ta%60;
	if(x<10) cout<<'0'<<x<<":";
	else cout<<x<<":";
	if(y<10) cout<<'0'<<y;
	else cout<<y;
	cout<<endl;
	x=tb/60;
	y=tb%60;
	if(x<10) cout<<'0'<<x<<":";
	else cout<<x<<":";
	if(y<10) cout<<'0'<<y;
	else cout<<y;
	return 0;
}