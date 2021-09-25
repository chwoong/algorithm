#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<set>
#include<stack>
#include<map>
using namespace std;

int p[200001];

int find(int n){
	if(p[n]<0) return n;
	p[n]=find(p[n]);
	return p[n];
}
void merge(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b) return;
	p[b]+=p[a];
	p[a]=b;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int f;
		scanf("%d",&f);
		memset(p,-1,sizeof(p));
		map<string,int> m;
		int number=0;
		while(f--){
			char a[21], b[21];
			scanf("%s %s",a,b);
			if(m.count(a)==0){
				m[a]=number;
				number++;
			}
			if(m.count(b)==0){
				m[b]=number;
				number++;
			}
			merge(m[a],m[b]);
			printf("%d\n",-p[find(m[a])]);
		}
	}
	return 0;
}