
'''
Q. Integer to English Words - AMAZON 2025

Convert a non-negative integer num to its English words representation.

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"



--------------------------------------------------------------------------------------------------

🔹 How to Explain in an Interview

1. Start with the Problem Statement

“We are asked to convert an integer into its English words representation. For example, 12340 should become Twelve Thousand Three Hundred Forty.”


2. Break Down the Core Idea

“Numbers in English are spoken in groups of three digits — thousands, millions, billions, etc. So the first step is to split the number into chunks of three digits each.
For example:

1,234,567 → 1 Million, 234 Thousand, 567.”
This shows you see the pattern.



3. Explain Why You Need a Helper Function

“Since each chunk is at most 3 digits, I created a helper function helper(n) that converts numbers less than 1000 into words. That way, I can reuse the same logic for billions, millions, thousands, and the remainder.”

This shows modularity in your thinking.

4. Walk Through the Helper Function

Explain cases inside helper:

    Case 1: n == 0 → return empty (no contribution).
    Case 2: n < 20 → use direct lookup (below_20 list).
    Case 3: 20 ≤ n < 100 → use tens[n // 10] and recurse for the ones digit.
    Case 4: n ≥ 100 → form "X Hundred" and recurse on the remainder.

“This recursion ensures we correctly handle cases like 342 → Three Hundred Forty Two.”



5. Explain the Big Number Splitting

“Now I split the number into groups of three digits:

billions = num // 1,000,000,000
millions = (num // 1,000,000) % 1000
thousands = (num // 1000) % 1000
remainder = num % 1000
Each one is at most 3 digits because of the % 1000.”

Show the interviewer with the given input:

For 12340:

billions = 0
millions = 0
thousands = 12
remainder = 340

6. Explain Combining Results

“Now I simply check each chunk. If it’s non-zero, I convert it with the helper and add the right unit (Billion, Million, Thousand). Finally, I trim extra spaces.”

So for 12340:

thousands = 12 → "Twelve Thousand"

remainder = 340 → "Three Hundred Forty"
→ Final: "Twelve Thousand Three Hundred Forty"

7. Summarize

End with a clear summary:

“In short, the solution works by breaking the number into 3-digit chunks, converting each chunk into words with a helper function, and then combining them with the correct scale units. This approach ensures correctness up to the maximum allowed 32-bit integer (2,147,483,647).”

'''

def numberToWords(num):
    # maps
    below_20 = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", 
                "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", 
                "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", 
                "Nineteen"]
    tens = ["", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        
    if num == 0:
        return "Zero"

    # helper for numbers < 1000
    def helper(n: int) -> str:
        if n == 0:
            return ""
        elif n < 20:
            return below_20[n] + " "
        elif n < 100:
            return tens[n // 10] + " " + helper(n % 10)
        else:
            return below_20[n // 100] + " Hundred " + helper(n % 100)

    # main units
    billions = num // 1000000000
    millions = (num // 1000000) % 1000
    thousands = (num // 1000) % 1000
    remainder = num % 1000

    print("b",billions)
    print("m",millions)
    print("t",thousands)
    print("r",remainder) 

    result = ""

    if billions:
        result += helper(billions) + "Billion "
    if millions:
        result += helper(millions) + "Million "
    if thousands:
        result += helper(thousands) + "Thousand "
    if remainder:
        result += helper(remainder)

    return result.rstrip()


ans = numberToWords(12340)
print(ans)