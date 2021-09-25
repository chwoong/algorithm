/*Å¥ »ç¿ë*/
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {

	int N, K;
	cin >> N >> K;
	string a;
	queue<int> q[21];
	long long frd=0;
	for (int i = 0; i < N; i++) {
		cin >> a;
		int x = a.length();
		q[x].push(i);
		while (i - q[x].front() > K) {
			q[x].pop();
		}
		frd += (q[x].size()-1);
	}
	cout << frd;
	
	return 0;
}