#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
#include<string>
#include<string.h>

using namespace std;
//0: on 1: none 2:off
int arr[100];
int a[100];
int b[100];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		if(s=="on") arr[i]=0;
		else if(s=="none") arr[i]=1;
		else arr[i]=2;
		scanf("%d %d",a+i,b+i);
	}
	int p=-1000000000;
	int q=1000000000;
	for(int j=n-1;j>=0;j--){
			if(arr[j]==0){
				p-=b[j];
				q-=a[j];
				p=max(0,p);
				q=max(0,q);
			}else if(arr[j]==2){
				p+=a[j];
				q+=b[j];
			}else{
				p=max(p,a[j]);
				q=min(q,b[j]);
			}
		}
	cout<<p<<' '<<q<<endl;
	p=-1000000000;
	q=1000000000;
	for(int j=0;j<n;j++){
			if(arr[j]==0){
				p+=a[j];
				q+=b[j];
			}else if(arr[j]==2){
				p-=b[j];
				q-=a[j];
				p=max(0,p);
				q=max(0,q);
			}else{
				p=max(p,a[j]);
				q=min(q,b[j]);
			}
		}
	cout<<p<<' '<<q;
	return 0;
}