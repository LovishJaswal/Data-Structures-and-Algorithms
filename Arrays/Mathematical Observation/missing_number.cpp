/*
=====================================================================
                          LeetCode 0268
                          Missing Number
=====================================================================

Pattern
-------
Mathematical Observation / Counting

Difficulty
----------
Easy

Problem
-------
Given an array nums containing n distinct numbers in the range
[0, n], return the only number that is missing from the array.

Pattern Recognition
-------------------
• The array contains every number from 0 to n except one.
• The sum of numbers from 0 to n can be calculated directly
  using the formula n × (n + 1) / 2.
• The difference between the expected sum and the actual sum
  gives the missing number.
• This eliminates the need for sorting or hashing.

Algorithm
---------
1. Calculate the expected sum of numbers from 0 to n.
2. Traverse the array and calculate the actual sum.
3. Subtract the actual sum from the expected sum.
4. Return the result.

Complexity
----------
Time  : O(n)
Space : O(1)

Key Takeaways
-------------
• Consecutive numbers often have mathematical formulas that
  eliminate unnecessary computation.
• Before sorting, check whether a mathematical property can
  solve the problem more efficiently.
• The expected value minus the actual value reveals the
  missing element directly.

=====================================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int temp = (nums.size()*(nums.size()+1))/2;
        int sum=0;
        for(int i=0; i<nums.size();i++){
            sum+=nums[i];
        }
        temp -= sum;
        return temp;
    }
};