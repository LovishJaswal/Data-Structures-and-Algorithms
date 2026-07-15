/*
=====================================================================
                          LeetCode 1094
                           Car Pooling
=====================================================================

Pattern
-------
Difference Array

Difficulty
----------
Medium

Problem
-------
A vehicle with a fixed seating capacity is traveling only in one
direction.

Each trip is represented as:

    [numPassengers, from, to]

meaning that 'numPassengers' get into the car at 'from' and leave
the car at 'to'. Note that 'to' is exclusive.

Return true if it is possible to complete all trips without
exceeding the vehicle's capacity at any point.

Pattern Recognition
-------------------
• Multiple range updates are performed on the same route.
• Updating every location for every trip would take O(n × m).
• A Difference Array allows each trip to be processed in O(1),
  followed by one Prefix Sum pass to recover the passenger count
  at every location.

Algorithm
---------
1. Find the maximum destination among all trips.
2. Create a Difference Array of size (maxLocation + 1).
3. For every trip:
      - Add passengers at the pickup location.
      - Remove passengers at the drop-off location.
4. Compute the Prefix Sum to obtain the number of passengers
   at every location.
5. If the passenger count exceeds the capacity at any location,
   return false.
6. Otherwise, return true.

Complexity
----------
Finding Maximum : O(m)
Range Updates   : O(m)
Prefix Sum      : O(n)
Space           : O(n)

where:
    m = number of trips
    n = maximum location

Key Takeaways
-------------
• Difference Arrays efficiently handle multiple range updates.
• Since the destination is exclusive:
      diff[from] += passengers
      diff[to]   -= passengers
• Unlike Corporate Flight Bookings, there is NO right + 1 because
  passengers leave exactly at the destination.
• The Difference Array remains unchanged until all updates are
  completed.
• One Prefix Sum reconstructs the actual passenger count.

What I Learned
--------------
• Prefix Sum and Difference Array are inverse operations. I should
  never keep converting between them after every update.
• Always determine whether the interval is:
      [L, R]  (inclusive)
      [L, R)  (exclusive)
  before writing the update formula.
• Never assume the last element contains the maximum value unless
  the problem guarantees it.
• Always verify whether the problem uses 0-based or 1-based
  indexing before implementing the solution.
• Don't forget edge cases at the first index (location 0 in this
  problem).

=====================================================================
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        int maxLocation = 0;

        for (const auto &trip : trips)
            maxLocation = max(maxLocation, trip[2]);

        vector<int> temp(maxLocation + 1, 0);

        for (int i = 0; i < trips.size(); i++) {
            temp[trips[i][1]] += trips[i][0];
            temp[trips[i][2]] -= trips[i][0];
        }

        if (temp[0] > capacity)
            return false;

        for (int x = 1; x < temp.size(); x++) {

            temp[x] += temp[x - 1];

            if (temp[x] > capacity)
                return false;
        }

        return true;
    }
};