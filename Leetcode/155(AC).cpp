//Min Stack <Easy>

#include "stdafx.h"

class MinStack {
public:

	void push(int x) {
		topp++;
		stack[topp] = x;
		if (x < min || topp == 0)
		{
			min = x;
		}
	}

	void pop() {
		topp--;
		if (stack[topp + 1] == min)
		{
			min = stack[0];
			for (int i = 1; i <= topp; i++) {
				if (min > stack[i])
					min = stack[i];
			}
		}
	}

	int top() {
		return stack[topp];
	}

	int getMin() {
		if (topp == -1)
		{
			return 0;
		}
		return min;
	}
private:
	int stack[100000];
	int topp = -1;
	int min;
};
int main()
{
	
}