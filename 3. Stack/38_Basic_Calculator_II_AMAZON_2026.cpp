#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/* Q. Basic Calculator II - AMAZON 2026

Given a string s which represents an expression, evaluate this expression and return its value. 
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Input: s = "3+2*2"
Output: 7

Input: s = " 3/2 "
Output: 1

Input: s = " 3+5 / 2 "
Output: 5


Intuition ---------------------------------------------------------------------------------

I solve this in one pass using a stack. I build each number digit by digit. Whenever I reach an operator or the end of the string, I process the previous operator. For + and -, I push the number (or its negative) onto the stack. For * and /, I pop the previous number from the stack, combine it with the current number, and push the result back. This handles operator precedence without needing parentheses or multiple passes. At the end, I sum all values in the stack. The time complexity is O(n) and the space complexity is O(n).

Now explain why multiplication works:

"When I encounter *, I don't perform multiplication immediately. I first finish reading the next number. Once I reach the next operator (or the end of the string), I have both operands:

the left operand is already on top of the stack,
the right operand is the current number (num).

I pop the left operand, compute left * num, and push the result back. This replaces the previous number with the multiplied result, so operator precedence is naturally maintained."

For the example 3+2*2, you can say:

Read 3
+  -> push 3      Stack = [3]

Read 2
*  -> previous operator was '+', so push 2
Stack = [3,2]

Read 2
End of string
Previous operator is '*'

Pop 2
2 * 2 = 4
Push 4

Stack = [3,4]

Sum = 7


Why this extra condition: i == s.size() - 1 ?
"I use i == s.size()-1 because the last number does not have a following operator to trigger evaluation. This condition acts as a virtual operator at the end of the string, ensuring the final number is processed.



*/

int calculate(string s) {
    // Time Compleixty: O(n)
    // Space complexity: O(n)

    int n = s.size();
    int result = 0;
    int num = 0;
    char op = '+';
    stack<int>st;

    for(int i=0;i<n;i++){
        char ch = s[i];

        if(isdigit(ch)){
            num = num * 10 + (ch - '0');
        }

        if ((!isdigit(ch) && ch != ' ') || i == s.size() - 1){
            if(op == '+'){
                st.push(num);
            }
            else if(op == '-'){
                st.push(-num);
            }
            else if(op == '*'){
                int top = st.top();
                st.pop();
                st.push(top*num);
            }
            else if(op == '/'){
                int top = st.top();
                st.pop();
                st.push(top/num);
            }

            op = ch;
            num = 0;
        }
    }

    while(!st.empty()){
        result+=st.top();
        st.pop();
    }

    return result;
}