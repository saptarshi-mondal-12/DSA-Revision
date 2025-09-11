#include <iostream>
using namespace std;

/* Q: Find a^b (a to the power of b) - AMAZON 2025
    
Example: a = 2, b = 5
Output: 32
Explanation: 2^5 = 2*2*2*2*2 = 32


--------------------------------------------------------------------------

Start with the naive way

If someone asks me to compute a to power b, the first idea is: multiply a with itself, b times.
That’s O(b) time. Works for small b, but if is huge (say 10^9), it’s too slow.


Optimal Example: 

a=2, b=9

Step 1:
result = 1*2=2
a=4
b=4

Step 2:
result = 2
a=16
b=2

Step 3:
result=2
a=256
b=1

Step 3:
result = 2*256 = 512
a=65536
b=0

ans = 512





*/



// Brute Soln ------------------------------------------------------------------------
double brute_power(double a, int b) {
    // Time complexity: O(b)
    // Space complexity: O(1)

    /* Intuition: The idea is to simply multiply a exactly b times using a iterative loop.*/
    
    // Edge cases:
    if (a == 0 && b == 0) return 1;
    if (a == 0 && b > 0) return 0;
    if (a == 0 && b < 0) return 1;
    if (a > 0 && b == 0) return 1;
    
    double pow = 1;

    // Multiply a for b times
    for (int i = 0; i < abs(b); i++){
        pow = pow * a;
    }

    // If exponent was negative → return reciprocal
    if (b < 0) {
        return 1.0 / pow;
    }
  	
    return pow;
}




// Optimal Soln -------------------------------------------------------------------------------
long long power(long long a, long long b) {
    // Time complexity: O(log b)
    // Space complexity: O(1)

    // Edge cases:
    if (a == 0 && b == 0) return 1;
    if (a == 0 && b > 0) return 0;
    if (a == 0 && b < 0) return 1;
    if (a > 0 && b == 0) return 1;


    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            result *= a;
        }
        a *= a;
        b /= 2;
    }
    return result;
}




int main() {
    long long a = 2, b = 4;

    // Brute soln
    cout << a << " to the power " << b << " is: " << brute_power(a, b) << endl;
    
    // Optimal soln
    cout << a << " to the power " << b << " is: " << power(a, b) << endl;
}