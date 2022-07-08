#include<iostream>

using namespace std;
#define MAX 200010
int N;
long long arr[200010];
long long mod(long long i){
	return i%(long long)1000000007;
}
class fenwick{
	public:
	long long fw[MAX]={0,};
	
	void update(int i,long long num){
		while(i<MAX){
			fw[i]=mod(fw[i]+num);
			i+=(i& -i);
		}
	}
	long long sum(int i){
		long long ret=0;
		while(i>0){
			ret=mod(ret+fw[i]);
			i -=(i&-i);
		}
		return ret;
	}
};


int main(){
	cin>>N;	
	long long multi=1;
	/* ���� ���� ��ġ���� ���ʿ� �ִ� ���� ������ ���ʿ� �ִ� ���� ��ġ �� ���� */
	fenwick less_num,less_sum;
	cin>>arr[1];
	/* +1���ִ� ������ ���� index�� 1���� �����ϴµ� ���� ��ġ�� 0�ϼ� �ֱ� �����̴� */
	less_num.update(arr[1]+1,1);
	/* �ش� index(arr[1]+1)�� arr[1]���� ä������ */
	less_sum.update(arr[1]+1,arr[1]);
	for(int i=2;i<=N;i++){
		cin>>arr[i];
		less_num.update(arr[i]+1,1);
		less_sum.update(arr[i]+1,arr[i]);
		/* ���� ���� ��ġ���� ���ʿ� �ִ� ���� ���� */
		long long y=less_num.sum(arr[i]);
		/* ���� ���� ��ġ���� ���ʿ� �ִ� ���� ��ġ �� */
		long long s= less_sum.sum(arr[i]);
		/* ������� ���� ���� ��ġ �� */
		long long sum=less_sum.sum(MAX-1);
		/* �̹� ���꿡 ���ؾ� �� �� */
		long long tmp=mod(mod(sum+mod(2*y*arr[i]))+1000000007-mod(2*s+mod(i*arr[i])));
		multi=mod(multi*tmp);
	}
	cout<<multi;
	return 0;
}