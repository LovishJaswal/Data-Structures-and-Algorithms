/*
=====================================================================
                          LeetCode 0643
              Maximum Average Subarray I
=====================================================================

Pattern
-------
Sliding Window (Fixed)

Difficulty
----------
Easy

Problem
-------
Given an integer array nums consisting of n elements and an integer k,
find the contiguous subarray of length k that has the maximum average
value and return that value.

Key Insight
-----------
The window size is fixed, so instead of recalculating the sum for every
subarray, update the current window by adding the incoming element and
removing the outgoing element.

Approach
--------
1. Calculate the sum of the first window of size k.
2. Store it as the current maximum sum.
3. Slide the window one position at a time:
   - Add the new element entering the window.
   - Remove the element leaving the window.
4. Update the maximum window sum if needed.
5. Return the maximum sum divided by k.

Complexity
----------
Time  : O(n)
Space : O(1)

What I Learned
--------------
• Fixed-size windows can be updated in constant time.
• Keep track of the window sum instead of recomputing it.
• Initialize variables before using them to avoid undefined behavior.
• For maximum average, it's enough to track the maximum sum and divide
  by k only once at the end.

=====================================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;

        // Calculate the first window sum
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double answer = sum;

        // Slide the window
        for (int j = k; j < nums.size(); j++) {
            sum += nums[j];
            sum -= nums[j - k];
            answer = max(answer, sum);
        }

        return answer / k;
    }
};