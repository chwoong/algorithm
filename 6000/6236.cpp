#include<iostream>
using namespace std;

long long arr[100001];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		scanf("%lld",arr+i);
	
	long long l=1;
	long long h=1000000000;
	while(l+1<h){
		long long mid=(l+h)/2;
		/*mid가 가능한지 확인*/
		long long havemoney=0;
		/*인출횟수*/
		int tmp=0;
		bool pb=true;
		for(int i=0;i<n;i++){
			/*모자라면 다시 k원 인출*/
			if(havemoney<arr[i]){
				havemoney=mid;
				tmp++;
			}
			/*인출액이 물건값보다 적으면 불가능*/
			if(havemoney<arr[i]){
				pb=false;
				break;
			}
			/*가능하면*/
			if(havemoney>=arr[i]){
				havemoney-=arr[i];
			}
		}
		/*가능하면*/
		if(pb && tmp<=m) h=mid; 
		/*불가능하면*/
		else l=mid;
	}
	cout<<h;
	return 0;
}