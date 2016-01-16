//Implement Queue using Stacks	<Easy>
#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

class Queue {
private:
	stack<int> in;
	stack<int> out;
public:
	void push(int x) {
		in.push(x);
	}

	void pop(void) {
		if (in.size() == 0 && out.size() == 0)
			return;
		if(out.size()== 0) {
			while (in.size() != 0) {
				out.push(in.top());
				in.pop();
			}
		}
		out.pop();
	}

	int peek(void){
		if(out.size() == 0) {
			while(in.size() != 0) {
				out.push(in.top());
				in.pop();
			}
		}
		return out.top();
	}

	bool empty(void) {
		if (in.size() != 0 || out.size() != 0)
			return false;
		return true;
	}
};

void test() {
	Queue q1;
	cout << q1.empty() << endl;
	q1.push(1);
	cout << q1.peek() << endl;
	q1.push(2);
	cout << q1.peek() << endl;
	q1.push(3);
	cout << q1.peek() << endl;
	q1.pop();
	cout << q1.peek() << endl;
	cout << q1.empty() << endl;

}

int main() {
	test();
	system("pause");
}