/*질문게시판 확인용*/
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
int N, M;
int cnt, result;
bool arr[51][51];

// 3x3 이상 
int Check_over() {
	
	for (int i=0; i<=N-3; i++) {
		for (int j=0; j<=M-3; j++) {
			
			if (arr[i][j] == false) {
				for (int x=i; x<i+3; x++) {
					for (int y=j; y<j+3; y++) {
						arr[x][y] = !arr[x][y];
					}
				}
				cnt++;
			}

		}
	}
	
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (arr[i][j] == false) return -1;
		}
	}
	
	return cnt;
}

// 3x3 미만 
int Check_under() {
	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (arr[i][j] == false) return -1;
		}
	}
	return 0;
}

int main () {
	
	// 입력
	scanf("%d %d", &N, &M);
	for (int k=0; k<2; k++) {
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				int temp;
				scanf("%1d", &temp);
				if (k==0)
					arr[i][j] = temp;
                // A원소와 B원소가 같으면 true, 다르면 false
				else if (k==1 && temp == arr[i][j]) arr[i][j] = true;
				else if (k==1 && temp != arr[i][j]) arr[i][j] = false;
			}
		}
	}

	
	// 처리
	if (N >=3 && M >=3)
		result = Check_over();
	else 
		result = Check_under(); 
	
	printf("%d", result); 

	return 0;
}