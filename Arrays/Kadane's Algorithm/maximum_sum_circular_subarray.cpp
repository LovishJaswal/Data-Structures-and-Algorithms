/*
=====================================================================
                          LeetCode 0918
                  Maximum Sum Circular Subarray
=====================================================================

Pattern
-------
Kadane's Algorithm (Circular Array)

Difficulty
----------
Medium

Problem
-------
Given a circular integer array nums, return the maximum
possible sum of a non-empty subarray.

A subarray may wrap around the end of the array, but
each element can be included at most once.

Pattern Recognition
-------------------
Ask yourself:

• Can the answer be a normal subarray or a wrapped subarray?
• Can Kadane's Algorithm find the normal maximum subarray?
• Can a wrapped subarray be viewed as removing a minimum subarray?

If YES, use Kadane twice.

Approach
--------
• Find the total sum of the array.
• Run Kadane to find the maximum subarray sum.
• If every element is negative, return the maximum subarray sum.
• Run Kadane again to find the minimum subarray sum.
• Compute the wrapped sum:

    total_sum - minimum_subarray_sum

• Return the larger of:
    - maximum subarray sum
    - wrapped subarray sum

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
Wrapped Sum

total_sum - min_sum
↓
Return

max(max_sum, wrapped)

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
• Initially thought the wrapped sum was

    max_sum - min_sum

Correct

    wrapped = total_sum - min_sum

Reason:
A wrapped subarray is the entire array
excluding the minimum subarray.

-----------------------------------------------------

Mistake 2
• Forgot the all-negative edge case.

Correct

    if(max_sum < 0)
        return max_sum;

Reason:
Otherwise,

    total_sum - min_sum

becomes 0 by removing the entire array,
which is not a valid non-empty subarray.

Key Takeaways
-------------
• Run Kadane twice: maximum and minimum.
• Wrapped Sum = Total Sum − Minimum Subarray Sum.
• Handle the all-negative case separately.
• Final answer:

    max(max_sum, wrapped)

=====================================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int current_max = nums[0];
        int max_sum = nums[0];
        int total_sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            total_sum += nums[i];
        }

        for(int i = 1; i < nums.size(); i++){
            current_max = max(current_max + nums[i], nums[i]);
            max_sum = max(current_max, max_sum);
        }

        if(max_sum < 0){
            return max_sum;
        }

        int current_min = nums[0];
        int min_sum = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            current_min = min(current_min + nums[i], nums[i]);
            min_sum = min(current_min, min_sum);
        }

        int wrapped = total_sum - min_sum;

        return max(wrapped, max_sum);
    }
};