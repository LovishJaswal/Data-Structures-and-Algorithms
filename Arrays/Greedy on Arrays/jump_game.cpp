/*
=====================================================================
                          LeetCode 0055
                            Jump Game
=====================================================================

Pattern
-------
Greedy (Maximum Reach)

Difficulty
----------
Medium

Problem
-------
You are given an integer array nums where each element represents
your maximum jump length from that position.

Return true if you can reach the last index, otherwise return false.

Pattern Recognition
-------------------

• Maintain the farthest index that can be reached so far.
• Traverse the array from left to right.
• If the current index is beyond the farthest reachable index,
  the last index cannot be reached.
• Otherwise, update the farthest reachable index.
• If the farthest reachable index reaches or passes the last index,
  return true.

Approach Evolution
------------------

Start
↓
Maximum Reach = 0
↓
Traverse Array
↓
Current Index Reachable?
↓
Update Maximum Reach
↓
Reached Last Index?
↓
Answer

Complexity
----------

Time  : O(n)
Space : O(1)

Key Takeaways
-------------
• Think in terms of the farthest reachable index instead of actual jumps.
• Greedy maintains a reachable boundary while scanning the array.
• If the current index exceeds the maximum reachable index,
  there is no valid path forward.
• Update the maximum reachable index using:
  max(maxReach, i + nums[i]).

=====================================================================
*/

#include <vector>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
// Greedy (Maximum Reach)
/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums[0] == 0 && nums.size() != 1){
            return false;
        }
        if(nums[0] == 0 || nums.size() == 1){
            return true;
        }

        int maxi = 0;

        for(int i = 0; i < nums.size(); i++){

            if(i > maxi){
                return false;
            }

            if(i <= maxi){
                if(nums[i] == 0){
                    continue;
                }else{
                    maxi = max(maxi, i + nums[i]);
                }
            }

            if(maxi >= nums.size() - 1){
                return true;
            }
        }

        return false;
    }
};