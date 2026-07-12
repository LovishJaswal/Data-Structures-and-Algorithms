/*
=====================================================================
                          LeetCode 0283
                           Move Zeroes
=====================================================================

Pattern
-------
Two Pointers

Difficulty
----------
Easy

Problem
-------
Given an integer array nums, move all the 0's to the end while
maintaining the relative order of the non-zero elements.

The operation must be performed in-place.

Pattern Recognition
-------------------
• The array must be modified in-place.
• The relative order of non-zero elements must remain unchanged.
• One pointer tracks the position of the next zero, while the
  other searches for the next non-zero element to swap into place.

Algorithm
---------
1. Initialize two pointers:
      - left points to the first zero encountered.
      - right searches for the next non-zero element.
2. If nums[left] is non-zero, move both pointers forward.
3. If nums[right] is zero, move only the right pointer.
4. Otherwise, swap nums[left] and nums[right], then move both
   pointers forward.
5. Continue until either pointer reaches the end of the array.

Complexity
----------
Time  : O(n)
Space : O(1)

What I Learned
--------------
• Two pointers can efficiently modify an array in-place.
• Different pointers can have different responsibilities.
• Swapping only occurs when a non-zero element is found after a zero.
• Maintaining relative order is a common indicator for a two-pointer approach.

=====================================================================
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int left = 0;
        int right = 0;

        while (left < nums.size() && right < nums.size()) {

            if (nums[left] != 0) {
                left++;
                right++;
            }
            else if (nums[right] == 0) {
                right++;
            }
            else {
                swap(nums[left], nums[right]);
                left++;
                right++;
            }
        }
    }
};