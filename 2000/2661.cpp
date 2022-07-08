#include<iostream>

using namespace std;

int N;
int cnt=0;
int ans[80];
/*ans[i]���� ���� �������� Ȯ��
  ������ ans[0] ~ ans[i-1]������ ���� ���� �� ���̴�.
  ���� ������ ans[i]�� �߰��ż� ���� ������ �Ǵ����� Ȯ������.
*/
bool isGood(int i){
	int len=(i+1)/2;
	int judge=len;
	for(int l=1;l<=len;l++){
		for(int x=1;x<=l;x++){
			if(ans[i-l+x]!=ans[i-2*l+x]) {judge--;break;}
		}
	}
	if(judge==0) {return true;}
	return false;
}

/* ans[i]�� �ִ� dfs, ��Ʈ��ŷ�Ұ��� */
void dfs(int i){
	for(int tmp=1;tmp<=3 && cnt==0 ;tmp++){
		/* �ٷ� �� �� �װ� �ٸ� ���ڷ� �ֱ� */
		if(tmp!=ans[i-1]) {
			ans[i]=tmp;
			if(isGood(i)){
				if(i==N-1) {cnt=1;return;}
				dfs(i+1);
			}
		}
	}
}

int main(){
	cin>>N;
	ans[0]=1;
	dfs(1);
	for(int i=0;i<N;i++){
		cout<<ans[i];
	}
	return 0;
}