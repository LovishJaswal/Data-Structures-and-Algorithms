/*
=====================================================================
                          LeetCode 1109
                    Corporate Flight Bookings
=====================================================================

Pattern
-------
Difference Array

Difficulty
----------
Medium

Problem
-------
There are n flights numbered from 1 to n.

Each booking is represented as:

    [first, last, seats]

meaning that 'seats' passengers booked every flight from
first to last (inclusive).

Return an array where the ith element represents the total
number of seats booked for flight i.

Pattern Recognition
-------------------
• Multiple range updates are performed on the same array.
• Updating every element in every range would take O(n × m).
• A Difference Array allows each range update to be completed
  in O(1), followed by one Prefix Sum pass to recover the final
  values.

Algorithm
---------
1. Create a Difference Array of size n + 1 initialized with 0.
2. For every booking:
      - Add seats at the starting index.
      - Subtract seats immediately after the ending index.
3. After processing all bookings, compute the Prefix Sum.
4. The Prefix Sum converts the Difference Array into the final
   answer.
5. Ignore the extra sentinel element and return the result.

Complexity
----------
Range Updates : O(m)
Prefix Sum    : O(n)
Space         : O(n)

Key Takeaways
-------------
• Difference Arrays are used for multiple range updates.
• Every range update requires only two operations:
      diff[left]  += value
      diff[right + 1] -= value
• Do NOT rebuild the Difference Array after every update.
• Apply all updates first, then perform exactly one Prefix Sum.
• Prefix Sum and Difference Array are inverse operations:
      Difference → Prefix Sum → Original Array
• The extra (n + 1) element acts as a sentinel to safely mark
  the end of a range.

=====================================================================
*/

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector <int> temp(n+1, 0);
        for(int i=0; i<bookings.size(); i++){
            temp[(bookings[i][0])-1] += bookings[i][2];
            temp[bookings[i][1]] -= bookings[i][2];
        }
        for(int j=1; j<temp.size()-1; j++){
                temp[j] += temp[j-1];
            }
        temp.pop_back();
        return temp;
    }
};