#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#include<string.h>
#include<set>
#include<stdlib.h>
using namespace std;

long long N;
long long psum=0;

int main(){
	cin>>N;
	int sx(100),sy(100),bx(1),by(1);
	for(int i=0;i<N;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		sx=min(sx,x);
		bx=max(bx,x);
		sy=min(sy,y);
		by=max(by,y);
	}
	int l=max(bx-sx,by-sy);
	cout<<l*l;
	return 0;
}