#include<iostream>

using namespace std;

int N;
int cnt=0;
int ans[80];
/*ans[i]까지 좋은 수열인지 확인
  어차피 ans[0] ~ ans[i-1]까지는 좋은 수열 일 것이다.
  따라서 마지막 ans[i]가 추가돼서 나쁜 수열이 되는지만 확인하자.
*/
bool isGood(int i){
	int len=(i+1)/2;
	int judge=len;
	for(int l=1;l<=len;l++){
		for(int x=1;x<=l;x++){
			if(ans[i-l+x]!=ans[i-2*l+x]) {judge--;break;}
		}
	}
	if(judge==0) {return true;}
	return false;
}

/* ans[i]를 넣는 dfs, 백트래킹할거임 */
void dfs(int i){
	for(int tmp=1;tmp<=3 && cnt==0 ;tmp++){
		/* 바로 그 전 항과 다른 숫자로 넣기 */
		if(tmp!=ans[i-1]) {
			ans[i]=tmp;
			if(isGood(i)){
				if(i==N-1) {cnt=1;return;}
				dfs(i+1);
			}
		}
	}
}

int main(){
	cin>>N;
	ans[0]=1;
	dfs(1);
	for(int i=0;i<N;i++){
		cout<<ans[i];
	}
	return 0;
}