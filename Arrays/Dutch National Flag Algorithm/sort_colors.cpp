/*
=====================================================================
                          LeetCode 0075
                           Sort Colors
=====================================================================

Pattern
-------
Dutch National Flag (3-Way Partition)

Difficulty
----------
Medium

Problem
-------
Given an array nums containing only 0s, 1s, and 2s,
sort the array in-place without using the library sort function.

The array should be rearranged so that:

• All 0s come first.
• Then all 1s.
• Then all 2s.

Pattern Recognition
-------------------
Ask yourself:

• Does the array contain only a few distinct values?
• Can I partition the array into multiple regions?
• Can I maintain boundaries while scanning only once?

If YES, Dutch National Flag is the optimal solution.

Approach
--------
• Maintain three pointers:
    - low  : next position for 0
    - mid  : current element being processed
    - high : next position for 2
• Traverse while mid <= high.
• If current element is:
    - 0 → swap with low, increment low and mid.
    - 1 → increment mid.
    - 2 → swap with high, decrement high only.

Approach Evolution
------------------

Initialize:
low = 0
mid = 0
high = n - 1
↓
Process nums[mid]
↓
nums[mid] == 0 ?
    Swap(low, mid)
    low++
    mid++
↓
nums[mid] == 1 ?
    mid++
↓
nums[mid] == 2 ?
    Swap(mid, high)
    high--
    (Do NOT increment mid)
↓
Repeat until mid > high

Key Observation
---------------
Maintain four regions throughout the algorithm:

[0 ... low - 1]     -> All 0s
[low ... mid - 1]   -> All 1s
[mid ... high]      -> Unknown
[high + 1 ... n-1]  -> All 2s

When swapping with high, the new element at mid
has not been processed yet, so mid must not move.

Complexity
----------

Time  : O(n)

Space : O(1)

*/

#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};