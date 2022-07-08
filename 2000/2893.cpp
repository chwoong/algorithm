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

struct tri{
	int x,y,r;
	tri(int x_,int y_,int r_):x(x_),y(y_),r(r_){}
	bool operator<(const tri & t) const{
		return x<t.x;
	}
};

int n;
vector<tri> v;
double ans;

tri solve(tri a,tri b){
	if(b<a) swap(a,b);
	//���� a�� b�� �������� ���ٸ� case
	if(b.x+b.y>=a.x+a.y+a.r) return tri(0,0,0);
	if(b.x>=a.x+a.r) return tri(0,0,0);
	if(b.y+b.r<=a.y) return tri(0,0,0);
	
	//�� �ܿ��� �������� ������
	int x=b.x;
	int y=max(b.y,a.y);
	int r=min(b.y+b.r-y,a.x+a.y+a.r-x-y);
	return tri(x,y,r);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		v.push_back((tri){a,b,c});
	}
	sort(v.begin(),v.end());
	int k=1<<n;
	while(--k){
		//k�� �ش�Ǵ� �ﰢ�� ������ ������ ����
		//k�� �ش��ϴ� 1�� ����(with ���Թ���)
		int num=0;
		vector<int> t;
		tri cross=(tri){0,0,10000000};
		for(int i=0;i<n;i++)
			if(k & (1<<i)){
				cross=solve(cross,v[i]);
				num++;
			}
		if(num%2==1) ans+=(1<<(num-1))*(double)cross.r*cross.r/2.0;
		else ans-=(1<<(num-1))*(double)cross.r*cross.r/2.0;
	}
	printf("%.1f",ans);
}