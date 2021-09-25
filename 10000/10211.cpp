#include<iostream>
#include<algorithm>

using namespace std;

int arr[1000];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d ",arr+i);
		int ret=arr[0];
		int psum=arr[0];
		for(int i=1;i<n;i++){
			psum= max(psum+arr[i],arr[i]);
			ret=max(ret,psum);
		}
		printf("%d\n",ret);
	}
	return 0;
}