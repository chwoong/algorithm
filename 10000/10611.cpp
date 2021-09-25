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
vector<int> kind;
int num[100001];

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		num[x]++;
		if(num[x]==1) kind.push_back(x);
	}
	sort(kind.begin(),kind.end());
	int l=0;
	for(int i=0;i<=100000;i++){
		if(num[i]) l++;
	}
	int i=0;
	int j=100000;
	int turn=0;
	while(l>4){
		while(num[i]==0) i++;
		while(num[j]==0) j--;
		int nexti=*lower_bound(kind.begin(),kind.end(),i+1);
		vector<int>::iterator it=lower_bound(kind.begin(),kind.end(),j);
		it--;
		int nextj=*it;
		int m=min(num[i],num[j]);
		num[i]-=m;
		num[j]-=m;
		num[nexti]+=m;
		num[nextj]+=m;
		if(num[i]==0) l--;
		if(num[j]==0) l--;
	}
	while(l>=3){
		//turn:1 slavko
		//turn:0 mirko
		if(turn==0){
			while(num[i]==0){
				i++;
			}
			//num[i]는 1이상
			int next=*lower_bound(kind.begin(),kind.end(),i+1);
			num[i]--;
			num[next]++;
			if(num[i]==0) l--;
			turn=1;
		}else{
			while(num[j]==0){
				j--;
			}
			//num[j]는 1이상
			vector<int>::iterator it=lower_bound(kind.begin(),kind.end(),j);
			it--;
			int next=*it;
			num[j]--;
			num[next]++;
			if(num[j]==0) l--;
			turn=0;
		}
	}
	if(turn==0) puts("Slavko");
	else puts("Mirko");
	int ma=0;
	int mi=100000;
	for(int i=0;i<=100000;i++){
		if(num[i]>0){
			ma=max(i,ma);
			mi=min(i,mi);
		}
	}
	printf("%d %d",mi,ma);
	return 0;
}