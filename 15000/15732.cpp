#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
using namespace std;

#define MAX 1000000
struct val{
	int a,b,c;
}box[MAX];
int n,k;
long long d;

int main(){
	cin>>n>>k>>d;
	for(int i=0;i<k;i++){
		scanf("%d%d%d",&box[i].a,&box[i].b,&box[i].c);
	}
	int l=0;
	int h=n;
	while(l+1<h){
		long long num=0;
		int mid=(l+h)/2;
		for(int i=0;i<k;i++){
			if(box[i].a<=mid){
				num+=((min(box[i].b,mid)-box[i].a)/box[i].c)+1;
			}
		}
		/*최대 mid이하*/
		if(num>=d) h=mid;
		else l=mid;
	}
	cout<<h;
	return 0;
}