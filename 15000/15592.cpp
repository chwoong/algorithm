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

int ans=0;
int main(){
	int x1,y1,x2,y2;
	int a1,b1,a2,b2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
	x2--; y2--;
	a2--; b2--;
	int minx=1000;
	int maxx=-1000;
	int miny=1000;
	int maxy=-1000;
	for(int i=x1;i<=x2;i++){
		for(int j=y1;j<=y2;j++){
			//(i,j)가 안들어가 있으면
			if(a1<=i && i<=a2 && b1<=j && j<=b2) continue;
			minx=min(minx,i);
			maxx=max(maxx,i);
			miny=min(miny,j);
			maxy=max(maxy,j);
			ans++;
		}
	}
	if(ans==0) cout<<0;
	else cout<<(maxx-minx+1)*(maxy-miny+1);
	return 0;
}