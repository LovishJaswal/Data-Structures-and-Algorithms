/*
=====================================================================
                          LeetCode 1480
                    Running Sum of 1D Array
=====================================================================

Pattern
-------
Prefix Sum

Difficulty
----------
Easy

Problem
-------
Given an array nums, return the running sum of nums.

The running sum at index i is equal to the sum of all elements
from index 0 to i.

Pattern Recognition
-------------------
• Each element depends on the sum of all previous elements.
• Recomputing the sum for every index would be inefficient.
• The previous running sum can be reused to compute the next one.

Algorithm
---------
1. Create an answer vector.
2. Insert the first element of nums into answer.
3. Traverse the array from the second element onward.
4. Add the current element to the previous running sum.
5. Append the result to answer.
6. Return answer.

Complexity
----------
Time  : O(n)
Space : O(n)

Key Takeaways
-------------
• Running Sum is the simplest application of Prefix Sum.
• Each new prefix sum builds directly on the previous one.
• Prefix Sum avoids repeated summation of previous elements.

=====================================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        vector<int> answer;

        answer.push_back(nums[0]);

        if (nums.size() == 1) {
            return answer;
        }

        int i = 1;

        while (i < nums.size()) {
            answer.push_back(nums[i] + answer.back());
            i++;
        }

        return answer;
    }
};