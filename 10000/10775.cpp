#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define MAX 100000
int g,plane;
int p[MAX+1];

/*i게이트의 root를 구하자*/
int find(int i){
	if(p[i]==i) return i;
	return p[i]=find(p[i]);
}

int main(){
	cin>>g>>plane;
	for(int i=0;i<=g;i++)
		p[i]=i;
	int count=0;
	while(plane--){
		int i;
		scanf("%d",&i);
		/*p[i]: 1~i 게이트 중 채울 수 있는 것 중 가장 큰 게이트*/
		if(find(i)==0) break;
		if(find(i)==i){
			/*p[i]를 채우자*/
			count++;
			p[i]=find(i-1);
		}
		else{
			/*p[i]를 채우자*/
			count++;
			p[p[i]]=find(p[i]-1);
		}
	}
	cout<<count;
	return 0;
}