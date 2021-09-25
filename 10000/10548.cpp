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

/*coci 공식 해설 풀이*/
int n,m;
int a[1000][1000];
int h[1000][1000];
long long ans;
struct sq{
	int val,height,suc;
	long long num;
	sq(int v,int h,int s,long long n):val(v),height(h),suc(s),num(n){}
};

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&a[i][j]);
	
	//(i,j)이 오른쪽 아래 점인 직사각형의 개수를 구한다.
	//느낌은 히스토그램 상의 최대 넓이 구하는 스위핑 알고리즘과 같은 방식이다
	for(int i=0;i<n;i++){
		stack<sq> st;
		st.push(sq(0,0,0,0));
		for(int j=0;j<m;j++){
			h[i][j]=1;
			if(i!=0 && a[i][j]==a[i-1][j]) h[i][j]=h[i-1][j]+1;
			//h[i][j] 높이를 가진 (i,j)에서 시작하는 최대 직사각형 안에서 셀수있는 직사각형의 개수
			int suc=1;
			while(st.top().val==a[i][j] && st.top().height>h[i][j]){
				suc+=st.top().suc;
				st.pop();
			}
			long long res=suc*h[i][j];
			//그 외 h[i][j] 보다 높이가 작은 애들로부터 연장할 수 있는 직사각형 개수
			if(st.top().val==a[i][j]) res+=st.top().num;
			
			ans+=res;
			st.push(sq(a[i][j],h[i][j],suc,res));
		}
	}
	cout<<ans;	
	return 0;
}