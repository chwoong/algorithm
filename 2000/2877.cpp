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

int k;
string s="";
int main(){
	cin>>k;
	int tmp=1;
	int a=k;
	while(a/=2) tmp++;
	int b=1;
	for(int i=1;i<tmp-1;i++) b=b*2+1;
	if(k==(2*b+1)) b=2*b+1;
	if(k!=b) tmp--;
	k-=b;
	while(1){
		tmp--;
		if(k&(1<<tmp)) s+="7";
		else s+="4";
		if(tmp==0) break;
	}
	cout<<s;
	return 0;
}