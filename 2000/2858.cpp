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

int r,b;

int main(){
	cin>>r>>b;
	for(int i=3;i<r/2+2;i++){
		if(i*(r/2+2-i)==r+b){
			printf("%d %d",(r/2+2-i),i);
			break;
		}
	}
	return 0;
}