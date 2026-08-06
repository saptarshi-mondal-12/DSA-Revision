#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Basic Calculator - AMAZON 2026 

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Input: s = "1 + 1"
Output: 2

Input: s = " 2-1 + 2 "
Output: 3

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23

INTUITION -------------------------------------------------------------------------------------

1. Start with the approach

"The expression contains only +, -, and parentheses, so I can evaluate it in one pass. I maintain three variables:

result stores the value computed so far.
number stores the current multi-digit number.
sign tells whether the current number should be added or subtracted (+1 or -1).

The only challenge is handling parentheses, so I use a stack."

2. Explain each variable
result = 0;
number = 0;
sign = 1;
stack<int> st;

Say:

"number is built digit by digit. Whenever I encounter an operator, I add sign * number into result. sign simply remembers whether the next number is positive or negative."

3. Explain why the stack is needed

This is the most important part.

"Whenever I see (, I need to temporarily start evaluating a new expression. But before doing that, I must remember two things:

the result computed before the parenthesis
the sign before the parenthesis

So I push both onto the stack."

Example:

2-(3+4)

Explain:

"Before entering the parentheses:

result = 2
sign = -1

I save both on the stack and reset result = 0 and sign = 1 to evaluate the expression inside the parentheses independently."

4. Explain how ) works

Say:

"When I reach ), the expression inside the parentheses is completely evaluated.

First, I finish the current number.

Then I pop the saved sign and multiply the inner result by it.

Finally, I pop the saved result and add it."

Example:

2-(3+4)

inside = 7

7 × (-1) = -7

-7 + 2 = -5

This demonstrates exactly why both the sign and previous result are stored.

5. Explain time complexity

"Each character is processed exactly once, so the time complexity is O(n). The stack stores at most one pair (result, sign) for each level of nested parentheses, so the space complexity is O(n) in the worst case."

If the interviewer asks, "Why do you push result first and then sign?"

Answer:

"The push order just has to match the pop order. I push result first and sign second, so when I pop, I get the sign first because it is needed immediately to apply to the computed value inside the parentheses. After that, I pop the previous result and add it."

 
*/

int calculate(string s) {
    // Time Compleixty: O(n)
    // Space complexity: O(n)
        
    stack<long long> st;
    long long result = 0;
    long long number = 0;
    long long sign = 1;

    for (char c : s) {
        if (isdigit(c)) {
            number = number * 10 + (c - '0');
        }
        else if (c == '+') {
            result += sign * number;
            number = 0;
            sign = 1;
        }
        else if (c == '-') {
            result += sign * number;
            number = 0;
            sign = -1;
        }
        else if (c == '(') {
            // Push current result and sign
            st.push(result);
            st.push(sign);

            // Reset for the expression inside parentheses
            result = 0;
            sign = 1;
        }
        else if (c == ')') {
            result += sign * number;
            number = 0;

            // Apply the sign before '('
            result *= st.top();
            st.pop();

            // Add the result before '('
            result += st.top();
            st.pop();
        }
        // Ignore spaces
    }

    // Add the last number if any
    result += sign * number;

    return result;
}