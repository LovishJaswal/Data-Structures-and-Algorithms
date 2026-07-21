/*
=====================================================================
                          LeetCode 0229
                    Majority Element II
=====================================================================

Pattern
-------
Greedy

Algorithm
---------
Boyer-Moore Voting Algorithm (Extended)

Difficulty
----------
Medium

Problem
-------
Given an integer array nums of size n, return all elements
that appear more than ⌊n / 3⌋ times.

Pattern Recognition
-------------------
Ask yourself:

• Am I looking for elements occurring more than n/3 times?
• Can different elements cancel each other out?
• Is there a limit on how many valid answers can exist?

If YES, the Extended Boyer-Moore Voting Algorithm is the
optimal solution.

Approach
--------
First Pass (Find Candidates)
• Maintain two candidates and their counts.
• If the current element matches a candidate,
  increment its count.
• If a count becomes zero, replace that candidate
  with the current element.
• Otherwise, decrement both counts.

Second Pass (Verify Candidates)
• Reset both counts.
• Count the actual occurrences of both candidates.
• Add every candidate whose frequency is greater
  than ⌊n / 3⌋.

Approach Evolution
------------------

Initialize
Candidate1, Candidate2
Count1 = 0, Count2 = 0
↓
Traverse Array
↓
Matches Candidate1?
      Yes → Count1++
      No
↓
Matches Candidate2?
      Yes → Count2++
      No
↓
Count1 == 0 ?
      Yes → Candidate1 = Current
             Count1 = 1
      No
↓
Count2 == 0 ?
      Yes → Candidate2 = Current
             Count2 = 1
      No
↓
Count1--
Count2--
↓
Repeat Until End
↓
Reset Counts
↓
Count Actual Frequencies
↓
Return Verified Candidates

Key Observation
---------------
At most two elements can appear more than ⌊n / 3⌋ times.

If three different elements each appeared more than
⌊n / 3⌋ times, their total occurrences would exceed n,
which is impossible.

Therefore, tracking two candidates is sufficient.

Complexity
----------

Time  : O(n)
Space : O(1)

*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> answer;

        int candidate_one = 0;
        int candidate_two = 0;
        int count_one = 0;
        int count_two = 0;

        // First Pass: Find Potential Candidates
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == candidate_one) {
                count_one += 1;
            } else if (nums[i] == candidate_two) {
                count_two += 1;
            } else if (count_one == 0) {
                candidate_one = nums[i];
                count_one = 1;
            } else if (count_two == 0) {
                candidate_two = nums[i];
                count_two = 1;
            } else {
                count_one -= 1;
                count_two -= 1;
            }
        }

        // Second Pass: Verify Candidates
        count_one = 0;
        count_two = 0;

        for (int x : nums) {
            if (x == candidate_one) {
                count_one++;
            } else if (x == candidate_two) {
                count_two++;
            }
        }

        if (count_one > nums.size() / 3) {
            answer.push_back(candidate_one);
        }

        if (candidate_two != candidate_one &&
            count_two > nums.size() / 3) {
            answer.push_back(candidate_two);
        }

        return answer;
    }
};