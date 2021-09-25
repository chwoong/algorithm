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
	/* 나무 심은 위치보다 왼쪽에 있는 나무 개수와 왼쪽에 있는 나무 위치 합 펜윅 */
	fenwick less_num,less_sum;
	cin>>arr[1];
	/* +1해주는 이유는 펜윅 index가 1부터 시작하는데 나무 위치는 0일수 있기 때문이다 */
	less_num.update(arr[1]+1,1);
	/* 해당 index(arr[1]+1)에 arr[1]값을 채워넣음 */
	less_sum.update(arr[1]+1,arr[1]);
	for(int i=2;i<=N;i++){
		cin>>arr[i];
		less_num.update(arr[i]+1,1);
		less_sum.update(arr[i]+1,arr[i]);
		/* 나무 심은 위치보다 왼쪽에 있는 나무 개수 */
		long long y=less_num.sum(arr[i]);
		/* 나무 심은 위치보다 왼쪽에 있는 나무 위치 합 */
		long long s= less_sum.sum(arr[i]);
		/* 현재까지 심은 나무 위치 합 */
		long long sum=less_sum.sum(MAX-1);
		/* 이번 연산에 곱해야 할 값 */
		long long tmp=mod(mod(sum+mod(2*y*arr[i]))+1000000007-mod(2*s+mod(i*arr[i])));
		multi=mod(multi*tmp);
	}
	cout<<multi;
	return 0;
}