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
using namespace std;

#define MAX 1000000000
int n,m,c;
vector<int> t;
int main(){
	cin>>n>>m>>c;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		t.push_back(x);
	}
	sort(t.begin(),t.end());
	int l=-1;
	int h=MAX;
	while(l+1<h){
		int mid=(l+h)/2;
		//�ִ� ��� �ð��� mid�� ���ѵǾ��� �� ��������
		int f=t[0];
		int get=0;
		int bus=1;
		for(int i=0;i<n;i++){
			/*���ο� ������ �¿��� ��*/
			if(get==c || f+mid<t[i]){
				bus++;
				get=1;
				f=t[i];
			}else{
				get++;
			}
		}
		if(bus<=m) h=mid;
		else l=mid;
	}
	cout<<h;
	return 0;
}