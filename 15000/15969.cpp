#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
#include <set>
using namespace std;

int N;
int arr[1000];

int main(){
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>arr[i];
	sort(arr,arr+N);
	cout<<arr[N-1]-arr[0];
}