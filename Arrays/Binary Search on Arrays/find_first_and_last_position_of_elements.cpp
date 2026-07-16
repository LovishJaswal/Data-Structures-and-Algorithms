/*
=====================================================================
                          LeetCode 0034
          Find First and Last Position of Element in Sorted Array
=====================================================================

Pattern
-------
Binary Search

Difficulty
----------
Medium

Problem
-------
Given a sorted array of integers nums in non-decreasing order,
find the starting and ending position of a given target value.

If the target is not found, return {-1, -1}.

Pattern Recognition
-------------------

Approach 1
• Perform a normal binary search to locate any occurrence of target.
• Once found, expand towards both ends using two linear scans.
• Move the left pointer until the first occurrence is found.
• Move the right pointer until the last occurrence is found.
• Works correctly but the expansion can take O(n) time in the worst case.

Approach 2
• Instead of expanding linearly, use binary search twice.
• First binary search finds the leftmost occurrence.
• Second binary search finds the rightmost occurrence.
• Each search continues even after finding the target to locate the boundary.
• This maintains O(log n) time complexity.

Approach Evolution
------------------

Approach 1
Binary Search
↓
Target Found
↓
Linear Expansion Left & Right
↓
Answer

Approach 2
Binary Search (Left Boundary)
↓
Binary Search (Right Boundary)
↓
Answer

Complexity
----------

Approach 1
Time  : O(n)
Space : O(1)

Approach 2
Time  : O(log n)
Space : O(1)

Key Takeaways
-------------
• Finding any occurrence is often easier than finding boundaries.
• Expanding from the found index may degrade to linear time.
• Binary search can be modified to search for boundaries instead of
  immediately returning after finding the target.
• Running binary search twice still results in O(log n) complexity.

=====================================================================
*/

#include <vector>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// Approach 1 : Binary Search + Linear Expansion
/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        if (nums.size() == 0) {
            return {-1, -1};
        }

        int low = 0;
        int high = nums.size() - 1;
        int mid;

        while (low <= high) {

            mid = low + (high - low) / 2;

            if (nums[mid] == target) {

                while (nums[low] < target) {
                    low++;
                }

                while (nums[high] > target) {
                    high--;
                }

                return {low, high};
            }

            else if (nums[mid] < target) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return {-1, -1};
    }
};

/////////////////////////////////////////////////////////////////////////////
// Approach 2 : Binary Search for Left & Right Boundary
/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int mid;

        int left_range = -1;
        int right_range = -1;

        // Find first occurrence
        while (low <= high) {

            mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                left_range = mid;
                high = mid - 1;
            }

            else if (nums[mid] < target) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        // Find last occurrence
        low = 0;
        high = nums.size() - 1;

        while (low <= high) {

            mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                right_range = mid;
                low = mid + 1;
            }

            else if (nums[mid] < target) {
                low = mid + 1;
            }

            else {
                high = mid - 1;
            }
        }

        return {left_range, right_range};
    }
};