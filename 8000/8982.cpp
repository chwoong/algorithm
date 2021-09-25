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

typedef pair<int,int> P;
int n,k;
int s(1);
//i번째 선분의 양쪽 좌표와 높이
P x[300000];
long long h[300000];
map<P,int> m;
double t=0;
long long ans=0;

int minseg[600000];
int	numseg[600000];

//구간 내 최소 높이에 해당하는 index(그림 상 최대 높이)
void update_min(int pos,int val){
	pos+=s;
	minseg[pos]=val;
	for(pos/=2;pos>0;pos/=2){
		if(h[minseg[pos*2]]<h[minseg[pos*2+1]]){
			minseg[pos]=minseg[pos*2];
		}else{
			minseg[pos]=minseg[pos*2+1];
		}
	}
}

int minquery(int l,int r){
	int v=l;
	l+=s;
	r+=s;
	int ret=500001;
	while(l<=r){
		if(l%2==1){
			if(ret>h[minseg[l]]){
				v=minseg[l];
				ret=h[minseg[l]];
				l++;
			}
		}
		if(r%2==0){
			if(ret>h[minseg[r]]){
				v=minseg[r];
				ret=h[minseg[r]];
				r--;
			}
		}
		l/=2; r/=2;
	}
	return v;
}

//구간 내 구멍 개수
void update_num(int pos,int val){
	pos+=s;
	numseg[pos]=val;
	for(pos/=2;pos>0;pos/=2){
		numseg[pos]=numseg[pos*2]+numseg[pos*2+1];
	}
}

int numquery(int l,int r){
	l+=s;
	r+=s;
	int ret=0;
	while(l<=r){
		if(l%2==1) ret+=numseg[l++];
		if(r%2==0) ret+=numseg[r--];
		l/=2; r/=2;
	}
	return ret;
}

void solve(int l,int r,int hi){
	//l부터 r번째 선분 중에 가장위에 있는 선분 index=j
	if(l>r) return;
	int j=minquery(l,r);
	int height=h[j];
	int num=numquery(l,r);
	if(num>0){
		t+=(double)(x[r].second-x[l].first)*(double)(height-hi)/(double)num;
		ans-=(long long)(x[r].second-x[l].first)*(long long)(height-hi);
		solve(l,j-1,height);
		solve(j+1,r,height);
	}
}

int main(){
	cin>>n;
	//선분 개수
	int j=0;
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(i==0) continue;
		h[j]=b;
		if(i%2==1) x[j].first=a;
		else {
			x[j].second=a;
			ans+=(long long)(x[j].second-x[j].first)*h[j];
			m[x[j]]=j;
			j++;
		}
	}
	while(s<j) s*=2;
	for(int i=0;i<j;i++){
		update_min(i,i);
	}
	cin>>k;
	for(int i=0;i<k;i++){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		update_num(m[P(a,c)],1);
	}
	solve(0,j-1,0);
	//printf("%.2f\n",t);
	printf("%lld",ans);
	return 0;
}