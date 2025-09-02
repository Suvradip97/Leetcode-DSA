

/*


476. Number Complement

The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

Constraints:

1 <= num < 231


Intuition
When asked to find the complement of an integer, the idea is to flip every bit in its binary representation—changing 0s to 1s and 1s to 0s. For example, the complement of 5 (which is 101 in binary) is 010, which is 2 in decimal.
Approach
Determine the Binary Length: First, calculate the bit length of the integer. This is the number of bits required to represent the number in binary.
Create a Mask: Generate a binary number (mask) that has all bits set to 1 for the same length as the number's binary representation. This mask helps in flipping all bits when XORed with the original number.
Flip the Bits: Perform the XOR operation between the number and the mask. XORing with 1 flips the bit (0 becomes 1 and 1 becomes 0).
Return the Result: The result of the XOR operation is the complement of the original number.
Time complexity:
The time complexity is O(1). The operations (finding bit length, shifting bits, XOR operation) are all constant time operations regardless of the size of the integer.
Space complexity:
The space complexity is O(1). We are using a constant amount of extra space (only a few variables) that does not scale with the input size.

*/





class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;
        unsigned int mask = ~0;
        while (num & mask) {
            mask <<= 1;
        }
        return ~mask & ~num;
    }
};