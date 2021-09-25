#include<iostream>

using namespace std;


int n,l;
int p[300003];
bool store[300003]={0,};

int find(int i){
	if(p[i]<0) return i;
	return p[i]=find(p[i]);
}
/*i->j merge*/
void merge(int i,int j){
	int a=find(i);
	int b=find(j);
	if(a==b) return;
	else p[a]=b;
}

int main(){
	scanf("%d %d",&n,&l);
	for(int i=1;i<=l;i++)
		p[i]=-1;
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		/*과정 순서대로*/
		if(!store[a]){
			printf("LADICA\n");
			merge(a,b);
			store[a]=true;
			continue;
		}
		else if(!store[b]){
			printf("LADICA\n");
			store[b]=true;
			merge(b,a);
			continue;
		}
		if(!store[find(a)]){
			printf("LADICA\n");
			store[find(a)]=true;
			merge(a,b);
		}else{
			if(!store[find(b)]){
				printf("LADICA\n");
				store[find(b)]=true;
				merge(b,a);
			}else printf("SMECE\n");
		}
	}
	return 0;
}