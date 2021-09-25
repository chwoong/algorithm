#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

//2^20=1048576
/*¼¼±×¸ÕÆ®Æ®¸®*/
int segment[1<<22]={0,};

void update(int node,int val){
	while(node>=1){
		segment[node]+=val;
		node=node/2;
	}
}

int kth(int val){
	int node=1;
	while(1){
		if(node>=(1<<20)) return node;
		if(segment[2*node]>=val) {node=node*2;}
		else {val-=segment[2*node]; node=node*2+1;}
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d %d",&a,&b);
		/*»çÅÁ ²¨³¿*/
		if(a==1) {
			int n=kth(b)-((1<<20)-1);
			printf("%d\n",n);
			update(n+((1<<20)-1),-1);
		}
		/*»çÅÁ ³Ö°Å³ª »­*/
		else{
			scanf("%d",&c);
			/*node¿¡ c°ª¸¸Å­ º¯°æÇÔ*/
			update((1<<20)+b-1,c);
		} 
		
	}
	return 0;
}