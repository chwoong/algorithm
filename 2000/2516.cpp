#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<stack>
#include<map>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<cmath>
#include<time.h>
using namespace std;

int n;
//¾Ó¼÷°ü°è
vector<int> adj[100001];
int mon[100001]; //1or2

void f(int i){
	//°°Àº ±×·ì ³» ¾Ó¼÷ÀÇ ¸¶¸® ¼ö
	int num=0;
	for(int next:adj[i]){
		if(mon[i]==mon[next]) num++;
	}
	if(num>=2){
		if(mon[i]==1) mon[i]=2;
		else mon[i]=1;
		for(int next:adj[i]){
			f(next);
		}
	}
	
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int n;
		scanf("%d",&n);
		mon[i]=1;
		for(int j=0;j<n;j++){
			int x;
			scanf("%d",&x);
			//x¿Í i´Â ¾Ó¼÷
			adj[i].push_back(x);
		}
	}
	for(int i=1;i<=n;i++){
		f(i);
	}
	vector<int> one;
	vector<int> two;
	for(int i=1;i<=n;i++){
		if(mon[i]==1) one.push_back(i);
		else two.push_back(i);
	}
	int len=one.size();
	//¸ðµÎ °°Àº ¹øÈ£, ¾Æ¹«·¸°Ô³ª ±×·ì Áö¾îµµ µÊ
	if(len==0 || len==n){
		printf("1 1\n");
		printf("%d ",n-1);
		for(int i=2;i<=n;i++){
			printf("%d ",i);
		}
	}else{
		printf("%d ",(int)one.size());
		for(int ele:one){
			printf("%d ",ele);
		}
		printf("\n");
		printf("%d ",(int)two.size());
		for(int ele:two){
			printf("%d ",ele);
		}
	}
	return 0;
}