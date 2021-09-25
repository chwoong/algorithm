#include<iostream>
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y)) 

using namespace std;
int main() {
	int n;
	cin >> n;
	int* arr=new int[n+1];
	for (int i = 0; i < n; i++) {
		arr[i] = -1;
	}
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	for (int i = 4; i <= n; i++) {
		int a = 1000001,b,c,d;
		b = c = d = a;
		if (i % 3 == 0) {
			if (i % 2 == 0) {
				a = MIN(MIN(arr[i - 1], arr[i / 2]),arr[i/3])+1;
			}
			else {
				b = MIN(arr[i - 1], arr[i / 3])+1;
			}
		}
		else if (i % 2 == 0) {
			c = MIN(arr[i - 1], arr[i / 2])+1;
		}
		else{
			d = arr[i - 1] + 1;
		}
		arr[i] = MIN(MIN(a, b), MIN(c, d));
	}
	cout << arr[n];

	delete arr;
	return 0;
}