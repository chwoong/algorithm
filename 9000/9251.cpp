#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

/*lcs[i][j]:
ù��° ���ڿ��� 1...i������ sustring��
�ι�° ���ڿ��� 1...j������ substring����
longest common subsequence�� ����
*/
int lcs[1010][1010]={0,};

int main(){
	string s1,s2;
	cin>>s1>>s2;
	int len1=s1.size();
	int len2=s2.size();
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			if(s1[i-1]==s2[j-1]) lcs[i][j]=lcs[i-1][j-1]+1;
			else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
		}
	}
	cout<<lcs[len1][len2];
	return 0;
}