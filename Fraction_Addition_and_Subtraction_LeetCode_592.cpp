

/*

592. Fraction Addition and Subtraction

Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.

The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

 

Example 1:

Input: expression = "-1/2+1/2"
Output: "0/1"
Example 2:

Input: expression = "-1/2+1/2+1/3"
Output: "1/3"
Example 3:

Input: expression = "1/3-1/2"
Output: "-1/6"
 

Constraints:

The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
Each fraction (input and output) has the format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1, 10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above.
The number of given fractions will be in the range [1, 10].
The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.	

Intuition ✒️
When we see the problem, the goal is to add and subtract fractions represented as a string expression. Since fractions have different denominators, we'll need to manage this by finding a common denominator when adding or subtracting them. We also need to simplify the result to ensure it's in its irreducible form.
Approach 🚀
Extract the Fractions: First, we extract all the numerators and denominators from the string using regular expressions. This helps in breaking down the problem into smaller, manageable pieces.
Initialize the Result: Start with a fraction represented by a numerator of 0 and a denominator of 1, which effectively means 0/1.
Add/Subtract Fractions: Iterate over the extracted numerators and denominators, adding each fraction to the result using cross multiplication to handle the different denominators. This step effectively reduces multiple fraction operations to basic arithmetic.
Simplify the Result: After computing the final fraction, simplify it by dividing the numerator and denominator by their greatest common divisor (GCD).
Return the Fraction: Finally, return the result in the form of "numerator/denominator".
Time complexity:
The time complexity is O(n), where n is the length of the input string. This is because we are processing each character of the input string to extract numerators and denominators and then performing a fixed amount of work for each fraction.
Space complexity:
The space complexity is O(1), excluding the input and output, since we're only using a fixed amount of extra space for the numerator, denominator, and a few variables for calculations. The space used by the regular expression for extracting numbers is proportional to the number of fractions but remains constant with respect to the length of the input.



*/



#include <string>
#include <vector>
class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1;
        int i = 0, n = expression.size();
        while (i < n) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '-') sign = -1;
                i++;
            }
            int num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num *= sign;
            i++;
            int den = 0;
            while (i < n && isdigit(expression[i])) {
                den = den * 10 + (expression[i] - '0');
                i++;
            }
            numerator = numerator * den + num * denominator;
            denominator *= den;
            int gcdVal = gcd(abs(numerator), denominator);
            numerator /= gcdVal;
            denominator /= gcdVal;
        }
        return to_string(numerator) + "/" + to_string(denominator);
    }
};