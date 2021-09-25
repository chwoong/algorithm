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
#include<cmath>
#include<time.h>
using namespace std;

int tt;

int main(){
	cin>>tt;
	for(int t=1;t<=tt;t++){
		printf("Case #%d:\n",t);
		int r,c;
		scanf("%d %d",&r,&c);
		int m[25][25];
		for(int i=0;i<r;i++){
			string s;
			cin>>s;
			for(int j=0;j<c;j++){
				m[i][j]=s[j];
			}
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(m[i][j]!='?'){
					int k=i+1;
					while(k<r && m[k][j]=='?'){
						m[k][j]=m[i][j];
						k++;
					}
					k=i-1;
					while(k>=0 && m[k][j]=='?'){
						m[k][j]=m[i][j];
						k--;
					}
					
				}
			}
		}
		for(int i=0;i<r;i++){
			for(int j=1;j<c;j++){
				if(m[i][j]=='?' && m[i][j-1]!='?'){
					m[i][j]=m[i][j-1];
				}
			}
		}
		for(int i=0;i<r;i++){
			for(int j=c-1;j>0;j--){
				if(m[i][j]!='?' && m[i][j-1]=='?'){
					m[i][j-1]=m[i][j];
				}
			}
		}
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				printf("%c",m[i][j]);
			}
			puts("");
		}
	}
	return 0;
}