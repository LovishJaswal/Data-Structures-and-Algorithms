/*
=====================================================================
                          LeetCode 0324
                         Wiggle Sort II
=====================================================================

Pattern
-------
Dutch National Flag + Quickselect + Virtual Indexing

Difficulty
----------
Hard

Problem
-------
Rearrange the array so that:

nums[0] < nums[1] > nums[2] < nums[3] > ...

The answer is guaranteed to exist.

Pattern Recognition
-------------------
Ask yourself:

• Do I need the median of the array?
• Can I partition elements into:
      - Less than median
      - Equal to median
      - Greater than median
• Can I place larger elements at odd indices
  and smaller elements at even indices?

If YES, combine Quickselect, Dutch National Flag,
and Virtual Indexing.

Approach
--------
• Find the median using nth_element().
• Use the median as the pivot.
• Create a virtual index mapping so DNF visits
  odd indices before even indices.
• Perform Dutch National Flag partition:
    - > median  → front (odd positions)
    - == median → middle
    - < median  → back (even positions)

Approach Evolution
------------------

Find Median (nth_element)
↓
Virtual Index Mapping
↓
Initialize:
low, mid, high
↓
nums[virtual(mid)] > median ?
    Swap(low, mid)
    low++
    mid++
↓
nums[virtual(mid)] < median ?
    Swap(mid, high)
    high--
↓
Otherwise
    mid++
↓
Repeat until mid > high

Key Observation
---------------
The wiggle order can be achieved by:

• Placing larger numbers first into odd indices.
• Placing smaller numbers later into even indices.

Instead of physically rearranging indices,
use the mapping:

virtual(i) = (1 + 2 * i) % (n | 1)

This visits indices in the order:

For n = 6:
1 → 3 → 5 → 0 → 2 → 4

Applying Dutch National Flag on this virtual
ordering automatically produces the wiggle layout.

Complexity
----------

Time  : O(n)
        Average case (nth_element)

Space : O(1)

*/

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        // Find median
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int median = nums[n / 2];

        // Virtual index mapping
        auto index = [&](int i) {
            return (1 + 2 * i) % (n | 1);
        };

        // Dutch National Flag
        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high) {
            if (nums[index(mid)] > median) {
                swap(nums[index(low)], nums[index(mid)]);
                low++;
                mid++;
            }
            else if (nums[index(mid)] < median) {
                swap(nums[index(mid)], nums[index(high)]);
                high--;
            }
            else {
                mid++;
            }
        }
    }
};