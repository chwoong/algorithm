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

int x,y;
int r,c;
int val[1000][1000];
string ans="";
string s;
int main(){
	cin>>r>>c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf("%d",&val[i][j]);
		}
	}
	if(r&1){
		for(int i=0;i<r;i++){
			if(i&1) s.assign(c-1,'L');
			else s.assign(c-1,'R');
			ans+=s;
			if(i!=r-1) ans+='D';
		}
	}else if(c&1){
		for(int i=0;i<c;i++){
			if(i&1) s.assign(r-1,'U');
			else s.assign(r-1,'D');
			ans+=s;
			if(i!=c-1) ans+='R';
		}
	}else{
		int m=1000;
		//r,c,모두 짝수
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(((i+j)&1) && val[i][j]<m){m=val[i][j];x=i; y=j;}
			}
		}
		for(int i=0;i<2*(x/2);i++){
			if(i&1) s.assign(c-1,'L');
			else s.assign(c-1,'R');
			ans+=s;
			ans+='D';
		}
		//위아래 지그재그. 단,(x,y)를 제외하고
		for(int i=0;i<y;i++){
			if(i&1) ans+="UR";
			else ans+="DR";
		}
		for(int i=y+1;i<c;i++){
			if(i&1) ans+="RD";
			else ans+="RU";
		}
		if(2*(x/2)+2!=r) ans+='D'; 
		//
		for(int i=2*(x/2)+2;i<r;i++){
			if(i&1) s.assign(c-1,'R');
			else s.assign(c-1,'L');
			ans+=s;
			if(i!=r-1) ans+='D';
		}
	}
	cout<<ans;
	return 0;
}