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
#include <cstdio>
#include <fstream>
using namespace std;

/*dotory1158�� Ǯ�̸� ���� ���� */
/*https://www.go-hero.net/jam/17/name/dotory1158 */
int t;
int n,p;
long long arr[50];
long long brr[50][50];
vector<long long> x;
vector<long long> v[50];
int d[50];

int main(){
	cin>>t;
	for(int k=1;k<=t;k++){
		printf("Case #%d: ",k);
		cin>>n>>p;
		x.clear();
		for(int i=0;i<n;i++){
			scanf("%lld",arr+i);
			x.push_back(arr[i]);
		}
		for(int i=0;i<n;i++){
			v[i].clear();
			for(int j=0;j<p;j++){
				scanf("%lld",&brr[i][j]);
				v[i].push_back(brr[i][j]);
			}
		}
		for(int i=0;i<n;i++)
			sort(v[i].begin(),v[i].end());
		memset(d,0,sizeof(d));
		int ans=0;
		while(1){
			//x[i]�� �� d��ġ������ v[i][d[i]]�� �ּ� ����(����)�� �ִ��� ������
			long long val=0;
			for(int i=0;i<n;i++){
				//x*n*11/10 >= v  <=> n>=(10*v)/(11*x)
				val=max(val,(10*v[i][d[i]]+11*x[i]-1)/(11*x[i]));
			}
			bool tmp=true;
			for(int i=0;i<n;i++){
				//x * val * 9/10 <=v ���� Ȯ��
				if(x[i]*val*9> v[i][d[i]]*10){
					tmp=false;
					d[i]++;
					break;
				}
			}
			if(tmp){
				ans++;
				for(int i=0;i<n;i++) d[i]++;
			}
			bool q=false;
			for(int i=0;i<n;i++){
				if(d[i]==p) q=true; 
			}
			if(q) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}