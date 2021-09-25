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

int n,k;
int t[100];
char z[100];
int main(){
	cin>>k>>n;
	for(int i=0;i<n;i++){
		char s[20];
		scanf("%d %s",t+i,s);
		z[i]=s[0];
	}
	t[n]=210;
	int i=0;
	int p=t[i];
	while(p<210){
		if(z[i]=='T'){
			k++;
			if(k==9) k=1;
			p+=t[++i];
		}else{
			p+=t[++i];
		}
	}
	cout<<k;
	return 0;
}