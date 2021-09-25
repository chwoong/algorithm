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

int suc;
int val[30];
int ans;
int n;
void solve(int i,int k){
	if(i==n){
		if(k==suc) ans++;
		return;
	}else{	
		solve(i+1,k|(val[i]));
		solve(i+1,k);
	}
}
int main(){
	suc=1<<26;
	suc--;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int len=s.size();
		int tmp=0;
		for(int j=0;j<len;j++){
			tmp|=(1<<(s[j]-'a'));
		}
		val[i]=tmp;
	}
	int sets=1<<n;
	solve(0,0);
	cout<<ans;
	return 0;
}