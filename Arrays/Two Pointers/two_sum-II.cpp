/*
=====================================================================
                          LeetCode 0167
              Two Sum II - Input Array Is Sorted
=====================================================================

Pattern
-------
Two Pointers

Difficulty
----------
Medium

Problem
-------
Given a 1-indexed array of integers that is sorted in
non-decreasing order, find two numbers such that they add up to a
specific target.

Return the indices (1-indexed) of the two numbers.

It is guaranteed that exactly one solution exists, and the same
element cannot be used twice.

Pattern Recognition
-------------------
• The array is already sorted.
• We need to find a pair whose sum equals a target.
• A sorted array allows two pointers to eliminate impossible
  pairs without checking every combination.

Algorithm
---------
1. Initialize two pointers:
      - left at the beginning of the array.
      - right at the end of the array.
2. Calculate the sum of the two elements.
3. If the sum equals the target, return their indices.
4. If the sum is smaller than the target, move the left pointer
   to increase the sum.
5. If the sum is larger than the target, move the right pointer
   to decrease the sum.
6. Continue until the pair is found.

Complexity
----------
Time  : O(n)
Space : O(1)

What I Learned
--------------
• A sorted array is a strong indicator for the two-pointer pattern.
• Moving the left pointer increases the sum.
• Moving the right pointer decreases the sum.
• Two pointers reduce the time complexity from O(n²) to O(n).

=====================================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> answer;

        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {

            if (numbers[left] + numbers[right] == target) {
                answer.push_back(left + 1);
                answer.push_back(right + 1);
                return answer;
            }
            else if (numbers[left] + numbers[right] < target) {
                left++;
            }
            else {
                right--;
            }
        }

        return answer;
    }
};