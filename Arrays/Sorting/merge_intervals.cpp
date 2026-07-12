/*
=====================================================================
                          LeetCode 0056
                         Merge Intervals
=====================================================================

Pattern
-------
Merge Intervals

Difficulty
----------
Medium

Problem
-------
Given an array of intervals where intervals[i] = [start, end],
merge all overlapping intervals and return an array of the
non-overlapping intervals.

Key Insight
-----------
After sorting the intervals by their starting time, an interval
can only overlap with the last interval already present in the
merged result.

Approach
--------
1. Sort the intervals based on their starting points.
2. Add the first interval to the answer.
3. Traverse the remaining intervals.
4. If the current interval overlaps with the last merged interval,
   update the ending point.
5. Otherwise, add the current interval as a new merged interval.

Complexity
----------
Time  : O(n log n)
Space : O(n)

What I Learned
--------------
• Sorting transforms the problem into a linear traversal.
• Only the last merged interval needs to be checked for overlap.
• std::vector::back() allows direct modification of the last element.

=====================================================================
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end());

        answer.push_back({intervals[0][0], intervals[0][1]});

        for(int index = 1; index < intervals.size(); index++){
            if(intervals[index][0] <= answer.back()[1]){
                answer.back()[1] = max(answer.back()[1], intervals[index][1]);
            }else{
                answer.push_back({intervals[index][0], intervals[index][1]});
            }
        }

        return answer;
    }
};