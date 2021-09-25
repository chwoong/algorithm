#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main(){
	//capacity
	int a,b,c;
	//차있는 양
	int x,y,z;
	cin>>a>>x>>b>>y>>c>>z;
	for(int i=0;i<100;i++){
		//옮기는 양
		int k;
		if(i%3==0){
			k=min(x,b-y);
			x-=k;
			y+=k;
		}
		else if(i%3==1){
			k=min(y,c-z);
			y-=k;
			z+=k;
		}else{
			k=min(z,a-x);
			z-=k;
			x+=k;
		}
	}
	printf("%d\n%d\n%d",x,y,z);
	return 0;
}