#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
using namespace std;
int n;
vector<int> blo;
vector<int> bhi;
vector<int> glo;
vector<int> ghi;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x>0) bhi.push_back(x);
		else blo.push_back(-x);
	}
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x>0) ghi.push_back(x);
		else glo.push_back(-x);
	}
	sort(blo.begin(),blo.end());
	sort(glo.begin(),glo.end());
	sort(bhi.begin(),bhi.end());
	sort(ghi.begin(),ghi.end());
	int ans=0;
	int j;
	if(!glo.empty() && !bhi.empty()){
		j=glo.size()-1;
		for(int i=bhi.size()-1;i>=0;i--){
			if(bhi[i]<glo[j]){ans++; j--;}
			else continue;
		}
	}
	if(!blo.empty() && !ghi.empty()){
		j=blo.size()-1;
		for(int i=ghi.size()-1;i>=0;i--){
			if(ghi[i]<blo[j]){ans++; j--;}
			else continue;
		}
	}
	cout<<ans;
}