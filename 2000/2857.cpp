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

int main(){
	vector<int> v;
	for(int i=0;i<5;i++){
		string s;
		cin>>s;
		size_t f=s.find("FBI");
		if(f!=string::npos) v.push_back(i);
	}
	if(v.empty()) puts("HE GOT AWAY!");
	else{
		for(int ele:v) printf("%d ",ele+1);
	}
	return 0;
}