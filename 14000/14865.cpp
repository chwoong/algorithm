#include<iostream>
#include<string.h>
#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

typedef pair<int,int> P;
vector<P> v;
int N;
int main(){
	cin>>N;
	int a[2];
	int k=0;
	int x[1000000],y[1000000];
	for(int i=0;i<N;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	int i=0;
	while(1){
		int y1=y[i];
		int y2=y[(i+1)%N];
		if(y1<0 && y2>0) break;
		i++;
	}
	for(int j=i;j<i+N;j++){
		int x1=x[j%N];
		int y1=y[j%N];
		int x2=x[(j+1)%N];
		int y2=y[(j+1)%N];
		if((y1>0 && y2<0)||(y1<0 &&y2>0)){
			a[k++]=x1;
			if(k==2) {
				sort(a,a+2);
				v.push_back(P(a[0],a[1]));
				k=0;
			}
		}
	}
	sort(v.begin(),v.end());
	int len=v.size();
	int outmax=-1000000100;
	int inmax;
	int outsi=0;
	int insi=0;
	for(int i=0;i<len;i++){
		//가장 밖의 사각형 등장
		if(v[i].first>outmax){
			outsi++;
			insi++;
			outmax=v[i].second;
			inmax=v[i].second;
		}
		//현재 확인하는 사각형의 맨 오른쪽
		else if(v[i].first>inmax){
			inmax=v[i].second;
			insi++;
		}
		else{
			inmax=v[i].second;
		}
	}
	cout<<outsi<<" "<<insi;
	return 0;
}