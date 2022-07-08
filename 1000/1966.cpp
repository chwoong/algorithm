/*Queue*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	queue<int> q;
	int test;
	int num; /*��ü ������ ����*/
	int order;/*�˰����ϴ� ������ �� ��°�� �ִ°�*/
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> num;
		cin >> order;
		int *arr = new int[num];
		/*������ �߿䵵�� queue�� �Է�*/
		for (int j = 0; j < num; j++) {
			cin >> arr[j];
			if (j == order) {
				q.push(-arr[j]);
			}
			else {
				q.push(arr[j]);
			}
		}
		/*arr�� ������������ �߿䵵 �־��� �ִ� ����*/
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