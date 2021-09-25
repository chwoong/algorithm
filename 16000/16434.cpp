#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<string.h>
#include<deque>
#include<queue>
#include<utility>
using namespace std;

#define MAX 123460
long long n,satk;
/*ti={1,2}*/
int t[MAX];
long long a[MAX];
long long h[MAX];

int main(){
	scanf("%lld%lld",&n,&satk);
	for(int i=0;i<n;i++){
		scanf("%d",&t[i]);
		scanf("%lld%lld",&a[i],&h[i]);
	}
	long long l0=0;
	long long h0=(long long)1<<60;
	while(l0+1<h0){
		long long atk=satk;
		long long mid=(l0+h0)/2;
		long long nowp=mid;
		bool isdeath=false;
		for(int i=0;i<n;i++){
			/*몬스터*/
			if(t[i]==1){
				/*몬스터를 죽이기 위한 공격횟수*/
				long long step;
				step=(h[i]%atk==0?h[i]/atk:h[i]/atk+1);
				/*데미지 입은 횟수*/
				step-=1;
				/*얻은 데미지*/
				long long pain=a[i]*step;
				nowp-=pain;
				/*용사죽음*/
				if(nowp<=0){
					isdeath=true;
					break;
				}
			}
			/*체력회복*/
			if(t[i]==2){
				atk+=a[i];
				nowp=min(nowp+h[i],mid);
			}
		}
		if(isdeath) l0=mid;
		else h0=mid;
	}
	cout<<h0;
	return 0;
}