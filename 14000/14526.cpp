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
//usaco ���� �ش��� ���� �ۼ�

stack<int> paint;
int n;
int color[100010];
//�� Į���� �ּ� ��ġ�� �ִ� ��ġ ����
int l[100010];
int h[100010];

int main(){
	cin>>n;
	fill(l,l+100010,1000000);
	fill(h,h+100010,0);
	l[0]=0;
	h[0]=n+1;
	for(int i=1;i<=n;i++){
		scanf("%d",color+i);
		l[color[i]]=min(l[color[i]],i);
		h[color[i]]=max(h[color[i]],i);
	}
	int ans=0;
	for(int i=0;i<=n+1;i++){
		int c=color[i];
		if(i==l[c]){
			paint.push(c);
			ans=max(ans,(int)paint.size());
		}
		if(paint.top()!=c){
			cout<<-1;
			return 0;
		}
		if(i==h[c]){
			paint.pop();
		}
	}
	cout<<ans-1;
	return 0;
}