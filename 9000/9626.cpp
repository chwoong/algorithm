#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int m,n;
int u,l,r,d;
string x[10];
int main(){
	cin>>m>>n;
	cin>>u>>l>>r>>d;
	for(int i=0;i<m;i++){
		string s;
		cin>>s;
		x[i]=s;
	}
	for(int i=0;i<m+u+d;i++){
		for(int j=0;j<n+l+r;j++){
			if(i>=u && i<m+u && j>=l && j<n+l){
				cout<<x[i-u][j-l];
			}
			else if((i+j)%2) cout<<'.';
			else cout<<'#';
		}
		cout<<'\n';
	}
	return 0;
}