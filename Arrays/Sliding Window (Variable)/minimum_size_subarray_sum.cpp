/*
=====================================================================
                          LeetCode 0209
                  Minimum Size Subarray Sum
=====================================================================

Pattern
-------
Variable Sliding Window

Difficulty
----------
Medium

Problem
-------
Given an array of positive integers nums and a positive integer target,
return the minimal length of a contiguous subarray whose sum is
greater than or equal to target.

If there is no such subarray, return 0.

Pattern Recognition
-------------------

Approach 1
• Expand the window while the current sum is less than target.
• As soon as adding the next element reaches the target,
  start shrinking the window.
• Uses nums[right] + sum to decide whether to expand or shrink.
• Works conceptually but the logic becomes unnecessarily complex.
• The current element is treated separately from the window sum,
  making the implementation harder to reason about and easier to
  introduce bugs.

Approach 2
• Always include nums[right] into the window first.
• Once the window satisfies the condition (sum >= target),
  continuously shrink it while updating the answer.
• Every element enters and leaves the window at most once.
• Cleaner implementation and follows the standard Variable
  Sliding Window template.

Approach Evolution
------------------

Approach 1

Check next element
↓
Expand OR Shrink
↓
Repeat

Approach 2

Always Expand
↓
Window Valid?
↓
Shrink While Valid
↓
Repeat

Complexity
----------

Approach 1
Time  : O(n)
Space : O(1)

Approach 2
Time  : O(n)
Space : O(1)

Key Takeaways
-------------
• Both approaches achieve O(n) time complexity.
• Approach 1 works but is not the standard sliding window template.
• Separating nums[right] from the current window sum complicates the logic.
• The standard pattern is:
      Add
      ↓
      Shrink while needed
      ↓
      Continue
• The cleaner template is easier to generalize to problems like
  Longest Substring Without Repeating Characters and
  Fruits Into Baskets.

=====================================================================
*/

#include <vector>
#include <climits>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// Approach 1 : Conditional Expansion & Shrinking (Works but Less Optimal)
/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int sum = 0;
        int left = 0;
        int right = 0;
        int answer = INT_MAX;

        while (right < nums.size()) {

            if (nums[right] + sum < target) {

                sum += nums[right];
                right++;
            }

            else {

                while (nums[right] + sum >= target) {

                    answer = min(answer, right - left + 1);
                    sum -= nums[left];
                    left++;
                }
            }
        }

        if (answer == INT_MAX) {
            return 0;
        }

        return answer;
    }
};

/////////////////////////////////////////////////////////////////////////////
// Approach 2 : Standard Variable Sliding Window
/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int sum = 0;
        int left = 0;
        int right = 0;
        int answer = INT_MAX;

        while (right < nums.size()) {

            // Expand window
            sum += nums[right];

            // Shrink while window is valid
            while (sum >= target) {

                answer = min(answer, right - left + 1);

                sum -= nums[left];
                left++;
            }

            right++;
        }

        if (answer == INT_MAX) {
            return 0;
        }

        return answer;
    }
};