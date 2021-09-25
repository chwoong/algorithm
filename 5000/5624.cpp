#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int n;
int arr[5000];
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",arr+i);
	set<int> s1;
	set<int> s2;
	int num=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(s2.count(arr[i]-arr[j])) {num++;break;}
		}

		s1.insert(arr[i]);
		for(set<int>::iterator it=s1.begin();it!=s1.end();it++){
			s2.insert((*it)+arr[i]);
		}
	}
	cout<<num;
	return 0;
}