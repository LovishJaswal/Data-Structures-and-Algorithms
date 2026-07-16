/*
=====================================================================
                          LeetCode 0704
                         Binary Search
=====================================================================

Pattern
-------
Binary Search

Difficulty
----------
Easy

Problem
-------
Given a sorted array of integers nums arranged in ascending order,
return the index of target if it exists.

If the target is not present, return -1.

Pattern Recognition
-------------------
• The array is sorted.
• We need to efficiently search for a single element.
• After comparing with the middle element, one half of the array
  can always be discarded.
• This allows the search space to be reduced by half every iteration.

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
4. Return -1.

Complexity
----------
Time  : O(log n)
Space : O(1)

Key Takeaways
-------------
• Binary Search only works on a sorted search space.
• Each comparison eliminates half of the remaining elements.
• Use:
      mid = low + (high - low) / 2
  to safely compute the middle index.
• Continue searching while low <= high.

=====================================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while(low <= high){
            mid = low+(high-low)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return -1;
    }
};