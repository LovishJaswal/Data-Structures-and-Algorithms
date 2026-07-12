/*
=====================================================================
                          LeetCode 0217
                        Contains Duplicate
=====================================================================

Pattern
-------
Sorting

Difficulty
----------
Easy

Problem
-------
Given an integer array nums, return true if any value appears at least
twice in the array, and return false if every element is distinct.

Key Insight
-----------
After sorting the array, duplicate elements become adjacent, allowing
them to be detected with a single traversal.

Approach
--------
1. Sort the array in ascending order.
2. Traverse the array from the second element.
3. Compare each element with its previous element.
4. If two adjacent elements are equal, return true.
5. If no duplicates are found, return false.

Complexity
----------
Time  : O(n log n)
Space : O(1)

What I Learned
--------------
• Sorting can simplify comparison-based problems.
• After sorting, duplicates are always adjacent.
• A single traversal after sorting is enough to detect duplicates.

=====================================================================
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]){
                return true;
            }
        }
        return false;
    }
};