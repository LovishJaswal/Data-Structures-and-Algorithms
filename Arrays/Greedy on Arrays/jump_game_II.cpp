/*
=====================================================================
                          LeetCode 0045
                          Jump Game II
=====================================================================

Pattern
-------
Greedy (BFS Level Traversal)

Difficulty
----------
Medium

Problem
-------
You are given a 0-indexed array of integers nums where each element
represents the maximum jump length from that position.

Return the minimum number of jumps required to reach the last index.

You can assume that the last index is always reachable.

Pattern Recognition
-------------------

• Treat each jump as a BFS level.
• current_end represents the end of the current level.
• farthest stores the farthest index reachable while exploring
  the current level.
• When the current level is fully explored, increment the jump
  count and move to the next level.

Approach Evolution
------------------

Start
↓
Current Level
↓
Explore All Reachable Indices
↓
Update Farthest Reach
↓
End of Current Level?
↓
Jump++
↓
Move to Next Level
↓
Answer

Complexity
----------

Time  : O(n)
Space : O(1)

Key Takeaways
-------------
• Think in BFS levels instead of choosing individual jumps.
• current_end marks the boundary of the current jump.
• farthest stores the boundary of the next jump.
• Increment the jump count only after exploring the entire
  current level.

=====================================================================
*/

#include <vector>
#include <algorithm>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
// Greedy (BFS Level Traversal)
/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int farthest = 0;
        int current_end = 0;

        for(int i = 0; i < nums.size() - 1; i++) {

            farthest = max(farthest, i + nums[i]);

            if(i == current_end) {
                jumps++;
                current_end = farthest;
            }
        }

        return jumps;
    }
};