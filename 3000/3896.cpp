#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<set>
#include<stack>
using namespace std;
/*�� ���� �ּ� ���μ�*/
int minfactor[1300001];
vector<int> prime(1,0);

int main(){
	int t;
	cin>>t;
	/*100000��° �Ҽ����� ã��*/
	for(int i=1;i<=1300000;i++)
		minfactor[i]=i;
	/*�����佺�׳׽�*/
	for(int i=2;i<=1300000;i++){
		if(minfactor[i]==i){
			prime.push_back(i);
			if(i<=sqrt(1300000))
				for(int j=i*i;j<=1300000;j+=i)
					if(minfactor[j]==j) minfactor[j]=i;
		}
	}
	while(t--){
		int x;
		scanf("%d",&x);
		vector<int>::iterator it=lower_bound(prime.begin(),prime.end(),x);
		if(*it==x) printf("0\n");
		else printf("%d\n",*it-*(it-1));
	}
	return 0;
}