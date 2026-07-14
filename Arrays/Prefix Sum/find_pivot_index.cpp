/*
=====================================================================
                          LeetCode 0724
                         Find Pivot Index
=====================================================================

Pattern
-------
Prefix Sum

Difficulty
----------
Easy

Problem
-------
Given an integer array nums, return the pivot index.

The pivot index is the index where the sum of all the numbers
strictly to the left of the index is equal to the sum of all the
numbers strictly to the right of the index.

If no such index exists, return -1.

Pattern Recognition
-------------------
• We need left and right sums for every index.
• Recomputing both sums for every index would take O(n²).
• Prefix sums allow left and right sums to be obtained in O(1),
  resulting in an overall O(n) solution.

Algorithm
---------
1. Build a prefix sum array.
2. The last element of the prefix array is the total sum.
3. Check if index 0 is a pivot.
4. Traverse the remaining indices.
5. At each index:
      - Left sum = prefix[i - 1]
      - Right sum = total sum - prefix[i]
6. If both sums are equal, return the index.
7. If no pivot exists, return -1.

Complexity
----------
Time  : O(n)
Space : O(n)

Key Takeaways
-------------
• Prefix sums allow constant-time range sum calculations.
• Left and right sums can be derived without traversing the array
  repeatedly.
• Always handle boundary indices carefully (first and last element).

=====================================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        vector<int> prefix;

        int sum = 0;

        for (int x = 0; x < nums.size(); x++) {
            sum += nums[x];
            prefix.push_back(sum);
        }

        int leftsum = 0;

        if (leftsum == (prefix.back() - prefix[0])) {
            return 0;
        }

        for (int i = 1; i < prefix.size(); i++) {

            if (prefix[i - 1] == (prefix.back() - prefix[i])) {
                return i;
            }

        }

        return -1;
    }
};