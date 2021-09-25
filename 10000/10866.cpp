#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
using namespace std;


int main(){
	int N;
	cin>>N;
	int size=0;
	int x;
	deque<int> dq;
	while(N--){
		string s;
		cin>>s;
		switch(s[3]){
			case 'h':
				scanf("%d\n",&x);
				if(s[5]=='f') dq.push_front(x);
				else  dq.push_back(x);
				size++;
				break;
			case '_':
				if(s[4]=='f' &&size){
					printf("%d\n",dq.front());
					dq.pop_front();
					size--;
				}else if(size){
					printf("%d\n",dq.back());
					dq.pop_back();
					size--;
				}else{
					puts("-1");
				}
				break;
			case 'e':
				printf("%d\n",size);
				break;
			case 't':
				if(size) puts("0");
				else puts("1");
				break;
			case 'n':
				if(size) printf("%d\n",dq.front());
				else puts("-1");
				break;
			case 'k':
				if(size) printf("%d\n",dq.back());
				else puts("-1");
				break;
		}
	}
	return 0;
}