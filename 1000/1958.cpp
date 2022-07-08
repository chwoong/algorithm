#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<string.h>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

/*lcs[i][j]:
ù��° ���ڿ��� 1...i������ substring��
�ι�° ���ڿ��� 1...j������ substring��
����° ���ڿ��� 1...k������ substring����
longest common subsequence�� ����
*/
int lcs[102][102][102]={0,};
string s1,s2,s3;

int main(){
	cin>>s1>>s2>>s3;
	int len1=s1.size();
	int len2=s2.size();
	int len3=s3.size();
	for(int i=1;i<=len1;i++){
		for(int j=1;j<=len2;j++){
			for(int k=1;k<=len3;k++){
				if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1]) lcs[i][j][k]=lcs[i-1][j-1][k-1]+1;
				else lcs[i][j][k]=max(max(lcs[i-1][j][k],lcs[i][j-1][k]),lcs[i][j][k-1]);
			}
		}
	}
	cout<<lcs[len1][len2][len3];
	return 0;
}