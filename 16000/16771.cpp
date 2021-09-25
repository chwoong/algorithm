#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<utility>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

vector<int> a;
vector<int> b;
int main(){
	for(int i=0;i<10;i++){
		int x;
		scanf("%d",&x);
		a.push_back(x);
	}
	for(int i=0;i<10;i++){
		int x;
		scanf("%d",&x);
		b.push_back(x);
	}
	set<int> s;
	s.insert(0);
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			s.insert(-a[i]+b[j]);
		}
	}
	for(int i=0;i<10;i++){
		for(int j=i+1;j<10;j++){
			for(int k=0;k<10;k++){
				for(int l=k+1;l<10;l++){
					s.insert(-a[i]-a[j]+b[k]+b[l]);
				}
			}
		}
	}
	cout<<s.size();
	return 0;
}