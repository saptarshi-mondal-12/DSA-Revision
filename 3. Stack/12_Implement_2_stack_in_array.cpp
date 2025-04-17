// Implement 2 stacks in single array

// 1. Stack1 starts from the leftmost corner of the array, the first element in stack1 is pushed at index 0 of the array. 
// 2. Stack2 starts from the rightmost corner of the array, the first element in stack2 is pushed at index (n-1) of the array. 
// 3. Both stacks grow (or shrink) in opposite directions. 
// 4. To check for overflow, all we need to check is for availability of space between top elements of both stacks.
// 5. To check for underflow, all we need to check is if the value of the top of the both stacks  is between 0 to (n-1) or not.

#include <iostream>
#include <stdlib.h>

using namespace std;

class twoStacks {
	/*
	Time Complexity: Push operation: O(1), Pop operation: O(1)
	Space Complexity: O(N), Use of the array to implement stack.
	*/
	int* arr;
	int size;
	int top1, top2;

public:
	twoStacks(int n) // constructor
	{
		size = n;
		int arr[n];
		top1 = -1;
		top2 = size;
	}

	// Method to push an element x to stack1
	void push1(int x)
	{
		// There is at least one empty space for new element
		if (top1 < top2 - 1) {
			top1++;
			arr[top1] = x;
		}
		else {
			cout << "Stack Overflow";
			exit(1);
		}
	}

	// Method to push an element x to stack2
	void push2(int x)
	{
		// There is at least one empty space for new element
		if (top1 < top2 - 1) {
			top2--;
			arr[top2] = x;
		}
		else {
			cout << "Stack Overflow";
			exit(1);
		}
	}

	// Method to pop an element from first stack
	int pop1()
	{
		if (top1 >= 0) {
			int x = arr[top1];
			top1--;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}

	// Method to pop an element from second stack
	int pop2()
	{
		if (top2 < size) {
			int x = arr[top2];
			top2++;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}
};


int main()
{
	twoStacks ts(5);
	ts.push1(5);
	ts.push2(10);
	ts.push2(15);
	ts.push1(11);
	ts.push2(7);
	cout << "Popped element from stack1 is " << ts.pop1();
	ts.push2(40);
	cout << "\nPopped element from stack2 is " << ts.pop2();
	return 0;
}
