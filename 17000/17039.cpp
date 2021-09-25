#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<utility>
#include<string.h>
#include<set>
#include<stdlib.h>
#include<string>
#include<utility>
#include<stack>
using namespace std;

int arr[3];
int main(){
	for(int i=0;i<3;i++)
		scanf("%d",arr+i);
	sort(arr,arr+3);
	//Ã·ºÎÅÍ ¿¬¼Ó
	if(arr[0]+1==arr[1] && arr[1]+1==arr[2]){
		printf("%d\n%d",0,0);
	}
	else{
		if(arr[1]-arr[0]==2 || arr[2]-arr[1]==2){
			cout<<1<<endl;
		}else{
			cout<<2<<endl;
		}
		cout<<max(arr[1]-arr[0]-1,arr[2]-arr[1]-1);
	}
	return 0;
}