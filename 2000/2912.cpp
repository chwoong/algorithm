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
/* 풀이 출처:
https://m.blog.naver.com/PostView.nhn?blogId=jh20s&logNo=221332226003&proxyReferer=https%3A%2F%2Fwww.google.com%2F
*/
int n,c,m;
int hat[300001];
//num[i]: i칼라의 모자가 나온 난쟁이 index
vector<int> num[10001];

int main(){
	cin>>n>>c;
	for(int i=0;i<=10000;i++)
		num[i].push_back(0);
	for(int i=1;i<=n;i++){
		scanf("%d",hat+i);
		num[hat[i]].push_back(i);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int a,b;
		int curr=20;
		int ans=-1;
		scanf("%d %d",&a,&b);
		while(curr--){
			//srand(time(NULL));
			int r=hat[rand()%(b-a+1)+a];
			int cnt=upper_bound(num[r].begin(),num[r].end(),b)-lower_bound(num[r].begin(),num[r].end(),a);
			//[a,b]구간내 색깔 r의 모자 개수
			if(cnt>(b-a+1)/2) {ans=r;break;}
		}
		if(ans>=0) printf("yes %d\n",ans);
		else puts("no");
	}
	return 0;
}