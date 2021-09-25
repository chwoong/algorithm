#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 100000
int cnt[MAX+1];
int L[2*MAX+1];
int T[2*MAX+1];
long long sort_t[2*MAX+1];
long long sum_l;
long long sum_t;
long long seg[MAX*4][2];
int N,C;
long long ans;
void update(int node,int nodel,int noder,long long val,int pos,int ch){
	if(pos>noder||pos<nodel) return;
	if(nodel<=pos && pos<=noder){
		seg[node][ch]+=val;
		if(nodel==noder) return;
		int mid=(nodel+noder)/2;
		update(node*2,nodel,mid,val,pos,ch);
		update(node*2+1,mid+1,noder,val,pos,ch);
	}
}

long long query(int node,int nodel,int noder,int l,int r,int ch){
	/*°³¼ö*/
	if(ch==0){
		if(noder<l||nodel>r) return 0;
		if(l<=nodel&&noder<=r) return seg[node][0];
		int mid=(nodel+noder)/2;
		return query(node*2,nodel,mid,l,r,0)+query(node*2+1,mid+1,noder,l,r,0);
	}
	//sum
	else{
		if(noder<l||nodel>r) return 0;
		if(l<=nodel&&noder<=r) return seg[node][1];
		int mid=(nodel+noder)/2;
		return query(node*2,nodel,mid,l,r,1)+query(node*2+1,mid+1,noder,l,r,1);
	}
}

int main(){
	cin>>N>>C;
	for(int i=1;i<=N;i++){
		long long l,t;
		scanf("%lld %lld",&l,&t);
		L[i]=l;
		sort_t[i]=T[i]=t;
		cnt[t]++;
		sum_l+=l;
		sum_t+=t;
		update(1,1,MAX,1,t,0);
		update(1,1,MAX,t,t,1);
	}
	ans+=sum_l;
	ans-=sum_t*(N+1);
	sort(sort_t+1,sort_t+N+1);
	for(long long i=1;i<=N;i++)
		ans+=i*sort_t[i];
	printf("%lld\n",ans);
	for(int i=0;i<C;i++){
		long long n,r,t;
		scanf("%lld %lld %lld",&n,&r,&t);
		ans+=(r-L[n]);
		L[n]=r;
		ans-=(t-T[n])*(N+1);
		if(t>T[n]){
			ans-=T[n]*(query(1,1,MAX,1,T[n],0));
			ans+=t*(query(1,1,MAX,1,t,0)-cnt[t]);
			ans-=query(1,1,MAX,T[n]+1,t-1,1);
		}else if(t<T[n]){
			ans-=T[n]*(query(1,1,MAX,1,T[n],0)-cnt[T[n]]+1);
			ans+=t*(query(1,1,MAX,1,t,0)+1);
			ans+=query(1,1,MAX,t+1,T[n]-1,1);
		}
		cnt[T[n]]--;
		cnt[t]++;
		update(1,1,MAX,1,t,0);
		update(1,1,MAX,-1,T[n],0);
		update(1,1,MAX,t,t,1);
		update(1,1,MAX,-T[n],T[n],1);
		T[n]=t;
		printf("%lld\n",ans);
	}
}