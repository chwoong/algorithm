#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
using namespace std;

map<string,int> m;
int main(){
	int n;
	int arr[3000];
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		m[s]=i;
	}
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		arr[i]=m[s];
	}
	int num=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]<arr[j]) num++;
		}
	}
	cout<<num<<"/"<<n*(n-1)/2;
	return 0;
}