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

/*coci ���� �ؼ� Ǯ��*/
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
	
	//(i,j)�� ������ �Ʒ� ���� ���簢���� ������ ���Ѵ�.
	//������ ������׷� ���� �ִ� ���� ���ϴ� ������ �˰���� ���� ����̴�
	for(int i=0;i<n;i++){
		stack<sq> st;
		st.push(sq(0,0,0,0));
		for(int j=0;j<m;j++){
			h[i][j]=1;
			if(i!=0 && a[i][j]==a[i-1][j]) h[i][j]=h[i-1][j]+1;
			//h[i][j] ���̸� ���� (i,j)���� �����ϴ� �ִ� ���簢�� �ȿ��� �����ִ� ���簢���� ����
			int suc=1;
			while(st.top().val==a[i][j] && st.top().height>h[i][j]){
				suc+=st.top().suc;
				st.pop();
			}
			long long res=suc*h[i][j];
			//�� �� h[i][j] ���� ���̰� ���� �ֵ�κ��� ������ �� �ִ� ���簢�� ����
			if(st.top().val==a[i][j]) res+=st.top().num;
			
			ans+=res;
			st.push(sq(a[i][j],h[i][j],suc,res));
		}
	}
	cout<<ans;	
	return 0;
}