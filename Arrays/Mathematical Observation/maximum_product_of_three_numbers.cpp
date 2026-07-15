/*
=====================================================================
                          LeetCode 0628
                  Maximum Product of Three Numbers
=====================================================================

Pattern
-------
Mathematical Observation / Counting

Difficulty
----------
Easy

Problem
-------
Given an integer array nums, return the maximum product that can
be obtained by multiplying any three numbers.

Pattern Recognition
-------------------
• The maximum product is not always obtained from the three
  largest numbers.
• Two very small (negative) numbers multiplied together produce
  a positive number.
• Therefore, only two possibilities need to be considered:
      - Product of the three largest numbers.
      - Product of the largest number and the two smallest numbers.
• Finding these five values in one traversal eliminates the need
  for sorting.

Algorithm
---------
1. Traverse the array once.
2. Keep track of:
      - Largest element.
      - Second largest element.
      - Third largest element.
      - Smallest element.
      - Second smallest element.
3. Compute:
      - Product of the three largest numbers.
      - Product of the largest number and the two smallest numbers.
4. Return the larger of the two products.

Complexity
----------
Time  : O(n)
Space : O(1)

Key Takeaways
-------------
• The largest numbers do not always produce the maximum product.
• Negative numbers can increase the final product when multiplied
  together.
• Instead of sorting, maintain only the values required to compute
  the answer.
• Always consider edge cases involving negative numbers.

=====================================================================
*/

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int largest = INT_MIN;
        int s_largest = INT_MIN;
        int t_largest = INT_MIN;
        int smallest = INT_MAX;
        int s_smallest = INT_MAX;
        for(int i=0; i<nums.size();i++){
            if(nums[i] >= largest){
                t_largest = s_largest;
                s_largest = largest;
                largest = nums[i];
            }else if(nums[i] <= largest && nums[i] >= s_largest){
                t_largest = s_largest;
                s_largest = nums[i];
            }else if(nums[i] <= s_largest && nums[i] >= t_largest ){
                t_largest = nums[i];
            }
            if(nums[i] <= smallest){
                s_smallest = smallest;
                smallest = nums[i];
            }else if(nums[i] >= smallest && nums[i] <= s_smallest){
                s_smallest = nums[i];
            }
        }
        long long p1 = 1LL * largest * s_largest * t_largest;
        long long p2 = 1LL * largest * smallest * s_smallest;

        return (int)max(p1, p2);
    }
};