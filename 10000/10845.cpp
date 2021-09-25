/*큐 연습하기*/
#include <iostream>
#include <string>
using namespace std;

class ListNode {
public:
	int value;
	ListNode *next;

	ListNode() : next(nullptr) {}
	ListNode(int value1, ListNode *next1) : value(value1), next(next1) {};

};

class Queue {
public:
	int size1;
	ListNode *head, *tail;

	Queue() : size1(0), head(nullptr), tail(nullptr) {}
	~Queue() {
		ListNode *t1 = head, *t2;
		while (t1 != nullptr) {
			t2 = (*t1).next; // t1->next
			delete t1;
			t1 = t2;
		}
	}

	void push(int value) {
		if (size1 == 0) head = tail = new ListNode(value, nullptr);
		else {
			tail->next = new ListNode(value, nullptr);
			tail = tail->next;
		}
		size1++;
	}
	void front() {
		if (size1 == 0) {
			cout << -1 << endl;
		}
		else {
			cout << head->value << endl;
		}
			
	}
	void pop() {
		
		if (size1 == 0) {
			cout << -1 << endl;
		}
		else {
			ListNode *temp = head;
			head = temp->next;
			cout << temp->value <<endl;
			delete temp;
			size1--;
		}
	}
	void size() {
		cout << size1 << endl;
	}
	void back() {
		if (size1 == 0) {
			cout << -1 << endl;
		}
		else {
			cout << tail->value << endl;
		}
	}
	void empty() {
		if (size1 == 0) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
};

int main() {
	Queue Q;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string a;
		cin >> a;
		if (a=="push") {
			int k;
			cin >> k;
			Q.push(k);
		}
		else if (a=="front") {
			Q.front();
		}
		else if (a=="back") {
			Q.back();
		}
		else if (a=="empty") {
			Q.empty();
		}
		else if (a=="pop") {
			Q.pop();
		}
		else if (a=="size") {
			Q.size();
		}
	}

	return 0;
}