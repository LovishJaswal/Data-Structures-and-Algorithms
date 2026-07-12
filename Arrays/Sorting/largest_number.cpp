/*
=====================================================================
                          LeetCode 0179
                         Largest Number
=====================================================================

Pattern
-------
Custom Sorting (Comparator)

Difficulty
----------
Medium

Problem
-------
Given a list of non-negative integers, arrange them such that they
form the largest possible number and return it as a string.

Key Insight
-----------
The order of two numbers depends on which concatenation produces a
larger value. Compare (a + b) with (b + a) instead of comparing the
numbers individually.

Approach
--------
1. Sort the numbers using a custom comparator.
2. For two numbers a and b, place a before b if "ab" is larger than "ba".
3. If the largest number is 0, return "0" to avoid leading zeros.
4. Concatenate all numbers into the final string.

Complexity
----------
Time  : O(n log n)
Space : O(n)

What I Learned
--------------
• Not every sorting problem has a fixed sorting key.
• Custom comparators can compare relationships between two elements.
• Comparing concatenated strings can produce the globally optimal order.

=====================================================================
*/

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });

        if(nums[0] == 0){
            return "0";
        }

        string answer;
        for(int x : nums)
            answer += to_string(x);

        return answer;
    }
};