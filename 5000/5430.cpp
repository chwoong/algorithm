#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(){
	/* r은 누적 R명령어의 기우성 */
	int r=0,N,len;
	char buf;
	int num;
	
	string com;
	
	cin >> N;
	for(int i=0;i<N;i++){
		deque<int> ac;
		/* 명령어 입력*/
		cin >> com;
		int size=com.length();
		/* 배열 길이 */
		cin >> len;
		/* 덱에 숫자들 입력 */
		cin >> buf;
		if(len==1) {cin >>num>>buf; ac.push_back(num);}
		else if(len>1){
			for(int j=0;j<len;j++){
				cin >> num >> buf;	
				ac.push_back(num);
			}
		}else{
			cin >> buf;
		}
		/*-------------*/
		
		
		for(int k=0;k<size;k++){
			switch(com[k]){
				case 'R':
					r=(++r)%2;
					break;
				case 'D':
					if(len==0) {cout << "error"; len--; break;}
					/* r이면 리버스 되어있음 */
					if(r){
						ac.pop_back();
					}
					else{
						ac.pop_front();
					}
					len--;
					break;
			}
		}
		if(len>=0){
			cout<<"[";
			if(len>=1){
				if(r){
					cout << ac.back();
					ac.pop_back();
				}else{
					cout << ac.front();
					ac.pop_front();
				}
			for(int j=0;j<len-1;j++){
				if(r){
					cout << ","<<ac.back();
					ac.pop_back();
				}else{
					cout << ","<<ac.front();
					ac.pop_front();
				}
			}
			}
			cout<<"]";
		}
		cout << endl;
		r=0;
	}
	return 0;
}


