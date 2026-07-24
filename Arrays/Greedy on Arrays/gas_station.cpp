/*
=====================================================================
                          LeetCode 0134
                           Gas Station
=====================================================================

Pattern
-------
Greedy (Running Balance)

Difficulty
----------
Medium

Problem
-------
There are n gas stations arranged in a circle.

You are given two integer arrays:
• gas[i]  = amount of gas available at station i.
• cost[i] = gas required to travel from station i to station i + 1.

Return the starting gas station's index if you can travel around
the circuit exactly once in the clockwise direction.
Otherwise, return -1.

Pattern Recognition
-------------------

• Track the running fuel balance while traversing the stations.
• If the running balance becomes negative, the current starting
  station and every station before the current index cannot be
  valid starting points.
• Reset the running balance and start from the next station.
• If the total gas is less than the total cost, completing the
  circuit is impossible.

Approach Evolution
------------------

Compute Running Balance
↓
Running Balance < 0 ?
↓
Discard Current Start
↓
Start = Current Index
↓
Continue Traversal
↓
Total Balance >= 0 ?
↓
Answer

Complexity
----------

Time  : O(n)
Space : O(1)

Key Takeaways
-------------
• Transform the problem into a running balance:
  gas[i] - cost[i].
• A negative running balance eliminates an entire range of
  starting stations.
• Only one linear traversal is required.
• If total gas is less than total cost, no solution exists.

=====================================================================
*/

#include <vector>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
// Greedy (Running Balance)
/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int running_sum = 0;
        int answer = 0;
        int total_sum = 0;

        for(int i = 0; i < gas.size(); i++) {

            if(running_sum < 0) {
                running_sum = 0;
                answer = i;
            }

            running_sum += gas[i] - cost[i];
            total_sum += gas[i] - cost[i];
        }

        return (total_sum >= 0) ? answer : -1;
    }
};