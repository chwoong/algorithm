#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>
#include<cmath>

using namespace std;

int n;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int x1,y1,r1,x2,y2,r2;
		scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
		if(x1==x2 && y1==y2 && r1==r2) {printf("%d\n",-1); continue;}
		int arr[3];
		arr[0]=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		arr[1]=r1*r1;
		arr[2]=r2*r2;
		int m=(arr[0]>arr[1])?0:1;
		if(m==0) m=(arr[0]>arr[2])?0:2;
		else m=(arr[1]>arr[2])?1:2;
		double j;
		if(m==0) j=sqrt(arr[0])-sqrt(arr[1])-sqrt(arr[2]);
		else if(m==1) j=sqrt(arr[1])-sqrt(arr[0])-sqrt(arr[2]);
		else j=sqrt(arr[2])-sqrt(arr[0])-sqrt(arr[1]);
		
		if(j>0) printf("%d\n",0);
		else if(j==0) printf("%d\n",1);
		else printf("%d\n",2);
	}
	return 0;
}