#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<utility>
#include<string>
#include<string.h>

using namespace std;

bool isused[6];
string x[6];
string map[3];
int main(){
	for(int i=0;i<6;i++){
		string s;
		cin>>s;
		x[i]=s;
	}
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			for(int k=0;k<6;k++){
				if(i!=j && j!=k && k!=i){
					memset(isused,false,sizeof(isused));
					map[0]=x[i];
					map[1]=x[j];
					map[2]=x[k];
					isused[i]=true;
					isused[j]=true;
					isused[k]=true;
					int num=0;
					for(int p=0;p<3;p++){
						string s="";
						for(int q=0;q<3;q++){
							s+=map[q][p];
						}
						for(int a=0;a<6;a++){
							if(s==x[a]&&isused[a]==false){
								isused[a]=true;
								num++;
								break;
							}
						}
					}
					if(num==3){
						cout<<map[0]<<'\n';
						cout<<map[1]<<'\n';
						cout<<map[2]<<'\n';
						return 0;
					}
				}
			}
		}
	}
	cout<<0;
	return 0;
}