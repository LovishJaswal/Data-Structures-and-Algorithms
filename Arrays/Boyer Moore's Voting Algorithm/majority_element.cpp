/*
=====================================================================
                          LeetCode 0169
                         Majority Element
=====================================================================

Pattern
-------
Greedy

Algorithm
---------
Boyer-Moore Voting Algorithm

Difficulty
----------
Easy

Problem
-------
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than
⌊n / 2⌋ times.

You may assume that the majority element always exists.

Pattern Recognition
-------------------
Ask yourself:

• Is there an element occurring more than half the time?
• Can different elements cancel each other out?
• Can I solve it without using extra memory?

If YES, Boyer-Moore Voting Algorithm is the optimal solution.

Approach
--------
• Initialize a candidate and a vote count.
• Traverse the array.
• If the vote count becomes zero, choose the current element
  as the new candidate.
• If the current element equals the candidate,
  increment the vote count.
• Otherwise, decrement the vote count.
• After the traversal, the candidate is the majority element.

Approach Evolution
------------------

Initialize Candidate & Count
↓
Traverse Array
↓
Count == 0 ?
↓
Yes → Choose Current Element as Candidate
↓
Current Element == Candidate ?
      Yes           No
       ↓             ↓
   Count++       Count--
↓
Continue Until End
↓
Return Candidate

Greedy Observation
------------------
Whenever two different elements are encountered,
they cancel each other's votes.

Since the majority element appears more than n/2 times,
it cannot be completely canceled and will remain as the
final candidate.

Complexity
----------

Time  : O(n)
Space : O(1)

*/

#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
            }

            if (nums[i] == candidate) {
                count += 1;
            } else {
                count -= 1;
            }
        }

        return candidate;
    }
};