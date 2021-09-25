#include<iostream>
#include<vector>
using namespace std;

#define MAX 1000000
int minfactor[MAX+1];

int main(){
	vector<int>prime;
	for(int i=1;i<=MAX;i++)
		minfactor[i]=i;
	for(int i=2;i<=MAX;i++){
		if(minfactor[i]==i){
			prime.push_back(i);
			if(i<=1000)
				for(int j=i*i;j<=MAX;j+=i){
					minfactor[j]=i;
				}
		}
	}
	int len=prime.size()-1;
	while(1){
		int x;
		scanf("%d",&x);
		if(x==0) break;
		int a,b;
		int tmp=1;
		for(int i=1;i<len;i++){
			a=prime[i];
			b=*lower_bound(prime.begin(),prime.end(),x-a);
			if(a+b==x) {
				printf("%d = %d + %d\n",x,a,b);
				break;
			}
		}
	}
	return 0;
}