#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

#define INF 1000000000

int n;
int arr[3001];
int num[3001];
int f[3001];
//a[i]: i의 i미만의 친구 수
int a[3001];
int b[3001][3001];
//dp[i][j]: j까지 확인헀고 이때 i~j까지 같은 모둠이다. 이 때 앞으로 얻게 될 최소 분할 점수
int dp[3001][3001];

int solve(int i,int j){
	int &ret=dp[i][j];
	if(ret!=-1) return ret;
	if(j==n) return 0;
	ret=INF;
	//이번에 j+1 학생의 모둠을 결정해야 한다.
	//j+1번째 학생의 1~j까지의 친구 수 x
	//j+1번째 학생의 i~j까지의 친구 수 y
	//j+1번째 학생의 1~i-1까지의 친구 수 z
	int x=a[j+1];
	int z=b[j+1][i-1];
	int y=x-z;
	ret=min(ret,z+(j-i+1)-y+solve(i,j+1));
	ret=min(ret,x+solve(j+1,j+1));
	return ret;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		while(1){
			scanf("%d",&x);
			if(x==0) break;
			b[i][x]++;
			if(x<i) a[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(b[i][j]==0) b[i][j]=b[i][j-1];
			else b[i][j]=b[i][j-1]+1;
		}
	}
	memset(dp,-1,sizeof(dp));
	int ans=solve(1,1);
	printf("%d\n",ans);
	//지금까지의 누적 분할점수
	int res=0;
	int cnt=1;
	int k=1;
	arr[1]=cnt;
	for(int i=2;i<=n;i++){
		//i가 k~i-1까지의 모둠과 같은 모둠이 될지 안될지 확인하자
		//i번째 학생의 1~i-1까지의 친구 수 x
		//i번째 학생의 k~i-1까지의 친구 수 y
		//i번째 학생의 1~k-1까지의 친구 수 z
		int x=a[i];
		int z=b[i][k-1];
		int y=x-z;
		//같은 모둠이 되었을때 증가하는 분할점수
		int val=z+(i-k)-y;
		if(res+val+solve(k,i)==ans){
			arr[i]=cnt;
			res+=val;
		}else{
			arr[i]=++cnt;
			res+=x;
			k=i;
		}
	}
	for(int i=1;i<=n;i++){
		num[arr[i]]++;
	}
	printf("%d ",cnt);
	int i=1;
	while(i<=n){
		if(num[i]!=0) printf("%d ",num[i]);
		else break;
		i++;
	}
	return 0;
}
