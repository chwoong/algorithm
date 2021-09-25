#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
using namespace std;

struct vector2{
	int x,y;
	vector2(int x_,int y_):x(x_),y(y_){}
	int cross(vector2 & rhs){
		return x*rhs.y-y*rhs.x;
	}
};

int main(){
	int x1,y1,x2,y2,x3,y3;
	scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3);
	vector2 a(x2-x1,y2-y1);
	vector2 b(x3-x2,y3-y2);
	if(a.cross(b)>0) cout<<1;
	else if(a.cross(b)==0) cout<<0;
	else cout<<-1;
}