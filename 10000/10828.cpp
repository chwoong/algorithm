#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(){
	vector<int> v(10000);
	/*다음에 저장할 곳의 위치*/
	int pos=0;
	int n,x;
	cin>>n;
	int size=0;
	while(n--){
		string s;
		cin>>s;
		if(s=="push"){
			scanf("%d",&x);
			v[pos++]=x;
			size++;
		}
		if(s=="pop"){
			if(size){
				printf("%d\n",v[--pos]);
				size--;
			}else printf("-1\n");
		}
		if(s=="size"){
			printf("%d\n",size);
		}
		if(s=="empty"){
			if(size) printf("0\n");
			else printf("1\n");
		}
		if(s=="top"){
			if(size) printf("%d\n",v[pos-1]);
			else printf("-1\n");
		}
	}
	return 0;
}