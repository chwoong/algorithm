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
#include<cmath>
#include<time.h>
using namespace std;

int r,c;
vector<int> v[50];
int res[10];

int main(){
	cin>>r>>c;
	for(int i=0;i<r;i++){
		string s;
		cin>>s;
		int team;
		int order=0;
		bool flag=false;
		for(int j=0;j<c;j++){
			if(s[j]>='1' && s[j]<='9') {
				flag=true;
				team=s[j]-'0';
				order=max(order,j);
			}
		}
		if(flag) v[c-order].push_back(team);
	}
	int cnt=1;
	for(int i=0;i<50;i++){
		if(!v[i].empty()){
			for(int ele:v[i]){
				res[ele]=cnt;
			}
			cnt++;
		}
	}
	for(int i=1;i<=9;i++)
		cout<<res[i]<<endl;
	return 0;
}
