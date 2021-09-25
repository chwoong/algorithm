#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
#include<stack>

using namespace std;

stack<int> s[7];
int n,p;

int main(){
	cin>>n>>p;
	int count=0;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		/*그 줄에 눌러진 것이 없다면*/
		if(s[a].empty()){
			count++;
			s[a].push(b);
		}
		else{
			/*프렛 b보다 더 큰 프렛을 누르고 있는 손은 떼야 한다.*/
			while(1){
				if(s[a].empty()) {s[a].push(b); count++; break;}
				int x=s[a].top();
				if(x>b) {count++; s[a].pop();}
				else if(x==b) {break;}
				else{s[a].push(b); count++; break;}
			}
		}		
	}
	cout<<count;
	return 0;
}