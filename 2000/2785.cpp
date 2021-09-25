#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
#include<string>
#include<string.h>

using namespace std;

int n;
vector<int> len;
int need;
int link;
int i=0;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		len.push_back(x);
	}
	sort(len.begin(),len.end());
	
	need=n-1;
	link=0;
	while(link<need){
		if(len[i]+link<=need-1){
			need--;
			link+=len[i++];
		}else{
			link=need;
		}
	}
	cout<<link;
	return 0; 
}