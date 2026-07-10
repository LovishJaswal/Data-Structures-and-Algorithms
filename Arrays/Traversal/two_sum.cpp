/*
=====================================================================
                          LeetCode 0001
                             Two Sum
=====================================================================

Pattern
-------
Traversal

Difficulty
----------
Easy

Problem
-------
Given an integer array nums and an integer target, return the indices
of the two numbers such that they add up to target.

Key Insight
-----------
Since exactly one valid pair exists, check every possible pair until
the required sum is found.

Approach
--------
1. Traverse the array using the first loop.
2. For every element, traverse the remaining elements.
3. If the sum equals the target, return their indices.
4. If no pair exists, return an empty vector.

Complexity
----------
Time  : O(n²)
Space : O(1)

What I Learned
--------------
• Generate all unique pairs using nested loops.
• Start the second loop from x + 1 to avoid duplicate comparisons.
• Return immediately once the answer is found.

=====================================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int x=0; x<nums.size()-1; x++){
            for(int y=x+1; y<nums.size(); y++){
                if(nums[x]+nums[y] == target){
                    return {x, y};
                }
            }
        }
        return{};
    }
};