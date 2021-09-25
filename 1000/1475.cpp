#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
#include<map>
#include<cmath>

using namespace std;

int arr[10];

int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		arr[s[i]-'0']++;
	arr[6]=(arr[6]+arr[9]+1)/2;
	int tmp=0;
	for(int i=0;i<9;i++){
		tmp=max(tmp,arr[i]);
	}
	cout<<tmp;
	return 0;
}