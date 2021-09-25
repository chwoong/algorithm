/*Queue*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	queue<int> q;
	int test;
	int num; /*전체 문서의 개수*/
	int order;/*알고자하는 문서가 몇 번째에 있는가*/
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> num;
		cin >> order;
		int *arr = new int[num];
		/*문서에 중요도를 queue에 입력*/
		for (int j = 0; j < num; j++) {
			cin >> arr[j];
			if (j == order) {
				q.push(-arr[j]);
			}
			else {
				q.push(arr[j]);
			}
		}
		/*arr에 오름차순으로 중요도 넣어져 있는 상태*/
		sort(arr, arr + num);
		int map = num - 1;
		while (1) {
			while (abs(q.front()) != arr[map]) {
				int temp = q.front();
				q.pop();
				q.push(temp);
			}
			if (q.front() < 0) {
				cout << num - map << endl;
				while (!q.empty()) q.pop();
				break;
			}
			else {
				q.pop();
			}
			map--;
		}
	}

	return 0;
}