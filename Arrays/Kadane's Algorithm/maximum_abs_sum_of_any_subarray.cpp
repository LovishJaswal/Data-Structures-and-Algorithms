/*
=====================================================================
                          LeetCode 1749
               Maximum Absolute Sum of Any Subarray
=====================================================================

Pattern
-------
Kadane's Algorithm (Maximum + Minimum Subarray)

Difficulty
----------
Medium

Problem
-------
Given an integer array nums, return the maximum absolute sum
of any subarray.

The absolute sum of a subarray is the absolute value of
its total sum.

Pattern Recognition
-------------------
Ask yourself:

• Can the answer come from either a large positive sum
  or a large negative sum?
• Do I need the best subarray ending at each index?
• Can Kadane's Algorithm be applied twice?

If YES, run Kadane for both maximum and minimum subarrays.

Approach
--------
• Run Kadane once to find the maximum subarray sum.
• Run Kadane again to find the minimum subarray sum.
• Return the larger of:
    - abs(maximum subarray sum)
    - abs(minimum subarray sum)

Approach Evolution
------------------

Kadane (Maximum)
↓
Maximum Subarray Sum
↓
Kadane (Minimum)
↓
Minimum Subarray Sum
↓
Return

max(abs(max_sum), abs(min_sum))

DP Relation
-----------

Maximum

dpMax[i] = max(dpMax[i-1] + nums[i], nums[i])

Minimum

dpMin[i] = min(dpMin[i-1] + nums[i], nums[i])

Space Optimization
------------------

Instead of storing DP arrays,

current_max = dpMax[i]

current_min = dpMin[i]

Complexity
----------

Time  : O(n)
Space : O(1)

Mistakes I Made
---------------

Mistake 1
• Initially thought one Kadane pass was enough.

Correct

Run Kadane twice:
• Maximum Subarray
• Minimum Subarray

Reason:
The maximum absolute sum may come from a
large negative subarray.

-----------------------------------------------------

Mistake 2
• Tried taking abs() while building the subarray.

Correct

Take abs() only at the end.

Reason:
Kadane works on actual subarray sums, not their absolute values.

Key Takeaways
-------------
• Run Kadane twice: maximum and minimum.
• Extend the current subarray or start a new one.
• Final answer:

    max(abs(max_sum), abs(min_sum))

=====================================================================
*/

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int current_max = nums[0];
        int max_sum = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            current_max = max(current_max + nums[i], nums[i]);
            max_sum = max(current_max, max_sum);
        }

        int current_min = nums[0];
        int min_sum = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            current_min = min(current_min + nums[i], nums[i]);
            min_sum = min(current_min, min_sum);
        }

        return max(abs(max_sum), abs(min_sum));
    }
};