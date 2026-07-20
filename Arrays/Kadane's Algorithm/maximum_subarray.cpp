/*
=====================================================================
                          LeetCode 0053
                      Maximum Subarray
=====================================================================

Pattern
-------
Kadane's Algorithm (Dynamic Programming)

Difficulty
----------
Medium

Problem
-------
Given an integer array nums, find the contiguous subarray
(containing at least one number) which has the largest sum,
and return its sum.

Pattern Recognition
-------------------
Ask yourself:

• Do I need the maximum sum of a contiguous subarray?
• Does the decision at the current index depend only on the
  previous subarray?
• Should I continue the current subarray or start a new one?

If YES, Kadane's Algorithm is the optimal solution.

Approach
--------
• Assume the first element is the best subarray initially.
• Traverse the array from left to right.
• At every index, choose:
    - Extend the previous subarray.
    - Start a new subarray from the current element.
• Store the best subarray ending at the current index.
• Update the global maximum whenever a better sum is found.

Approach Evolution
------------------

Start with First Element
↓
For Every Next Element
↓
Continue Previous Subarray?
        OR
Start New Subarray?
↓
Choose Maximum
↓
Update Global Maximum
↓
Repeat Until End

DP Relation
-----------

Let

dp[i] = Maximum subarray sum ending at index i

Transition

dp[i] = max(dp[i-1] + nums[i], nums[i])

Space Optimization

Instead of storing the entire dp array,
store only the previous value.

current_sum = dp[i]

Complexity
----------

Time  : O(n)
Space : O(1)

Mistakes I Made
---------------

Mistake 1
• Initialized max_sum = 0.

Wrong

    int max_sum = 0;

Correct

    int max_sum = nums[0];

Reason:
If every number is negative,
the answer is the largest negative number,
not zero.

Example

    [-3, -2, -5]

Answer = -2

-----------------------------------------------------

Mistake 2
• Started current_sum from 0.

Wrong

    int current_sum = 0;

Correct

    int current_sum = nums[0];

Reason:
The first element itself forms the first valid subarray.

-----------------------------------------------------

*/

#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int max_sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            current_sum = max(current_sum + nums[i], nums[i]);
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};