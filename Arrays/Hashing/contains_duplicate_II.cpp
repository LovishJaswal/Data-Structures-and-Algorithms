/*
=====================================================================
                          LeetCode 0219
                    Contains Duplicate II
=====================================================================

Pattern
-------
Hashing (Value → Last Seen Index)

Difficulty
----------
Easy

Problem
-------
Given an integer array nums and an integer k, return true if there
are two distinct indices i and j in the array such that:

• nums[i] == nums[j]
• abs(i - j) <= k

Otherwise, return false.

Pattern Recognition
-------------------

Approach 1
• Traverse the array once.
• Store each number along with its most recent index.
• If the current number already exists in the HashMap,
  compare the current index with its last stored index.
• If the distance is less than or equal to k, return true.
• Otherwise, update the stored index to the current index.

Approach Evolution
------------------

Traverse Array
↓
HashMap
(Value → Last Seen Index)
↓
Duplicate Found?
↓
Check Distance
↓
Update Latest Index
↓
Answer

Complexity
----------

Approach 1
Time  : O(n)
Space : O(n)

Key Takeaways
-------------
• HashMaps can store additional information instead of just frequencies.
• Store only the most recent index because it gives the smallest
  possible distance to future occurrences.
• unordered_map::find() returns an iterator.
• If find() returns end(), the key does not exist.

=====================================================================
*/

#include <vector>
#include <unordered_map>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
// Approach 1 : HashMap (Value → Last Seen Index)
/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            auto it = mp.find(nums[i]);

            if (it != mp.end() && i - it->second <= k) {
                return true;
            }

            mp[nums[i]] = i;
        }

        return false;
    }
};