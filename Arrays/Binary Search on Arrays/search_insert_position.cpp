/*
=====================================================================
                          LeetCode 0035
                    Search Insert Position
=====================================================================

Pattern
-------
Binary Search

Difficulty
----------
Easy

Problem
-------
Given a sorted array of distinct integers and a target value,
return the index if the target is found.

If the target is not found, return the index where it would be
inserted while maintaining the sorted order.

Pattern Recognition
-------------------
• The array is sorted in ascending order.
• We need to find either the target or its correct insertion position.
• Binary Search efficiently narrows the search space by half after
  every comparison.
• When the target is not found, the final value of low represents
  the correct insertion index.

Algorithm
---------
1. Initialize two pointers:
      - low = 0
      - high = last index
2. While low <= high:
      - Compute the middle index.
      - If nums[mid] equals target, return mid.
      - If nums[mid] is smaller than target,
        search the right half.
      - Otherwise,
        search the left half.
3. If the loop ends, the target does not exist.
4. Return low, which is the correct insertion position.

Complexity
----------
Time  : O(log n)
Space : O(1)

Key Takeaways
-------------
• Binary Search requires a sorted array.
• Each comparison removes half of the remaining search space.
• Use:
      mid = low + (high - low) / 2
  to safely compute the middle index.
• When the target is absent, low points to the first position where
  the target can be inserted while preserving sorted order.

=====================================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while(low <= high){
            mid = low + (high-low)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};