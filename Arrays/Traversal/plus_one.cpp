/*
=====================================================================
                          LeetCode 0066
                             Plus One
=====================================================================

Pattern
-------
Traversal

Difficulty
----------
Easy

Problem
-------
Given an integer represented as an array of digits, increment the
integer by one and return the resulting array.

Key Insight
-----------
Instead of converting the array into a number, simulate the addition
process by propagating the carry from right to left.

Approach
--------
1. Start from the last digit.
2. If the current digit is less than 9, increment it and return.
3. Otherwise, change the digit to 0 and continue moving left.
4. If every digit becomes 0, insert 1 at the beginning.

Complexity
----------
Time  : O(n)
Space : O(1)

What I Learned
--------------
• Think in terms of carry propagation.
• Avoid unnecessary special cases.
• Return immediately once the carry is resolved.

=====================================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int last_index = digits.size()-1;
        if(digits[last_index] != 9){
            digits[last_index] += 1;
            return digits;
        }else{
            while(digits[last_index] == 9 && last_index >= 1){
                digits[last_index] = 0;
                last_index--;
            }
            if(last_index == 0 && digits[last_index] == 9){
                digits[last_index] = 0;
                digits.insert(digits.begin(), 1);
            }else{
                digits[last_index] += 1;
            }
        }
        return digits;
    }
};