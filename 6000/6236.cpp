#include<iostream>
using namespace std;

long long arr[100001];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		scanf("%lld",arr+i);
	
	long long l=1;
	long long h=1000000000;
	while(l+1<h){
		long long mid=(l+h)/2;
		/*mid�� �������� Ȯ��*/
		long long havemoney=0;
		/*����Ƚ��*/
		int tmp=0;
		bool pb=true;
		for(int i=0;i<n;i++){
			/*���ڶ�� �ٽ� k�� ����*/
			if(havemoney<arr[i]){
				havemoney=mid;
				tmp++;
			}
			/*������� ���ǰ����� ������ �Ұ���*/
			if(havemoney<arr[i]){
				pb=false;
				break;
			}
			/*�����ϸ�*/
			if(havemoney>=arr[i]){
				havemoney-=arr[i];
			}
		}
		/*�����ϸ�*/
		if(pb && tmp<=m) h=mid; 
		/*�Ұ����ϸ�*/
		else l=mid;
	}
	cout<<h;
	return 0;
}