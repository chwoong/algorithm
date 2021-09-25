#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
#include<math.h>
#include<cmath>
using namespace std;

struct vector2{
	double x,y;
	vector2(double x_,double y_):x(x_),y(y_){}
	double cross(const vector2& rhs){
		return x*rhs.y-y*rhs.x;
	}
	double norm(vector2& rhs){
		return hypot(x-rhs.x,y-rhs.y);
	}
	double dot(const vector2& rhs){
		return x*rhs.x+y*rhs.y;
	}
	vector2 operator-(const vector2& rhs){
		return vector2(x-rhs.x,y-rhs.y);
	}
	bool footisin(vector2& a,vector2& b){
		int dot1=(b-a).dot((*this)-a);
		int dot2=(a-b).dot((*this)-b);
		if(dot1*dot2>=0) return true;
		return false;
	}
};

vector<vector2> red;
vector<vector2> blue;

int main(){
	int n,m;
	double ans=1000000;
	cin>>n>>m;
	double a,b,c,d;
	for(int i=0;i<n;i++){
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
		blue.push_back(vector2(a,b));
		blue.push_back(vector2(c,d));
	}
	for(int i=0;i<m;i++){
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
		red.push_back(vector2(a,b));
		red.push_back(vector2(c,d));
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			/*선분 red[2*i], red[2*i+1]와
			  선분 blue[2*j], blue[2*j+1]사의 최소 거리*/
			ans=min(ans,red[2*i].norm(blue[2*j]));
			ans=min(ans,red[2*i].norm(blue[2*j+1]));
			ans=min(ans,red[2*i+1].norm(blue[2*j]));
			ans=min(ans,red[2*i+1].norm(blue[2*j+1]));
			if(red[2*i].footisin(blue[2*j],blue[2*j+1])) ans=min(ans,abs((blue[2*j]-blue[2*j+1]).cross(red[2*i]-blue[2*j+1])/blue[2*j].norm(blue[2*j+1]) ));
			
			if(red[2*i+1].footisin(blue[2*j],blue[2*j+1])) ans=min(ans,abs((blue[2*j]-blue[2*j+1]).cross(red[2*i+1]-blue[2*j+1])/blue[2*j].norm(blue[2*j+1]) ));
			
			if(blue[2*j].footisin(red[2*i],red[2*i+1])) ans=min(ans,abs((red[2*i]-red[2*i+1]).cross(blue[2*j]-red[2*i+1])/red[2*i].norm(red[2*i+1]) ));
			
			if(blue[2*j+1].footisin(red[2*i],red[2*i+1])) ans=min(ans,abs((red[2*i]-red[2*i+1]).cross(blue[2*j+1]-red[2*i+1])/red[2*i].norm(red[2*i+1]) ));
			
		}
	}
	printf("%.7f",ans);
}