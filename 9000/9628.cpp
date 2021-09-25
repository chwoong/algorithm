#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

int n;
double a[1000];
double b[1000];
double xmin=0;
double xmax=10000000;
int main(){
	cin>>n;
	double sum=0;
	for(int i=0;i<n;i++){
		scanf("%lf %lf",a+i,b+i);
		sum+=b[i];
	}
	for(int i=0;i<n-1;i++){
		int j=i+1;
		if(b[i]==b[j] && a[i]>=a[j]) continue;
		else if(b[i]==b[j] && a[i]<a[j]) {puts("-1"); return 0;}
		else if(b[i]<b[j]){
			xmax=min(xmax,(a[i]-a[j])/(b[j]-b[i]));
		}else if(b[i]>b[j]){
			xmin=max(xmin,(a[j]-a[i])/(b[i]-b[j]));
		}
	}
	if(xmin<=xmax) printf("%.12f",sum*xmin);
	else puts("-1");
	return 0;
}