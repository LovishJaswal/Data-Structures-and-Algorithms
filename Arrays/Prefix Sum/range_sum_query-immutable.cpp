/*
=====================================================================
                          LeetCode 0303
                    Range Sum Query - Immutable
=====================================================================

Pattern
-------
Prefix Sum

Difficulty
----------
Easy

Problem
-------
Given an integer array nums, handle multiple queries of the form:

    sumRange(left, right)

Return the sum of the elements between indices left and right
(inclusive).

Pattern Recognition
-------------------
• Multiple range sum queries are performed on the same array.
• Calculating each query by traversing the range would take O(n).
• Prefix sums allow each query to be answered in O(1) after an
  initial preprocessing step.

Algorithm
---------
1. Build a prefix sum array.
2. Store the cumulative sum at each index.
3. For each query:
      - If left == 0, return prefix[right].
      - Otherwise, subtract the prefix before left from the
        prefix at right.
4. Return the computed sum.

Complexity
----------
Preprocessing : O(n)
Each Query    : O(1)
Space         : O(n)

Key Takeaways
-------------
• Prefix Sum is ideal when multiple range sum queries are required.
• Preprocessing once can greatly reduce query time.
• The range sum formula is:
      prefix[right] - prefix[left - 1]

=====================================================================
*/

#include <vector>
using namespace std;

class NumArray {
public:
    vector<int> prefix;

    NumArray(vector<int>& nums) {

        int sum = 0;

        for (int x = 0; x < nums.size(); x++) {
            sum += nums[x];
            prefix.push_back(sum);
        }

    }

    int sumRange(int left, int right) {

        if (left == 0)
            return prefix[right];

        return prefix[right] - prefix[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left, right);
 */