/*
=====================================================================
                          LeetCode 0561
                          Array Partition
=====================================================================

Pattern
-------
Mathematical Observation / Counting

Difficulty
----------
Easy

Problem
-------
Given an integer array nums consisting of 2n integers, group these
integers into n pairs such that the sum of the minimum value of each
pair is maximized.

Return the maximum possible sum.

Pattern Recognition
-------------------
Approach 1
• Sorting places the numbers in increasing order.
• Pairing adjacent elements guarantees the maximum possible answer.
• Initially, the pairs were explicitly stored before computing the sum.

Approach 2
• The extra vector is unnecessary.
• After sorting, every alternate element is already the minimum of
  its pair.
• The answer can be computed directly while traversing.

Approach 3
• Sorting becomes the bottleneck (O(n log n)).
• The constraints guarantee:
      -10000 <= nums[i] <= 10000
• Since the value range is fixed, a frequency array can simulate
  the sorted order in linear time.
• Alternate elements are taken while traversing the frequencies,
  eliminating the need for comparison-based sorting.

Approach Evolution
------------------
Approach 1
Sort
↓
Store every pair
↓
Traverse pairs
↓
Answer

Approach 2
Sort
↓
Directly sum every alternate element
↓
Answer

Approach 3
Frequency Counting
↓
Simulate sorted order
↓
Take every alternate occurrence
↓
Answer

Complexity
----------

Approach 1
Time  : O(n log n)
Space : O(n)

Approach 2
Time  : O(n log n)
Space : O(1)

Approach 3
Time  : O(n)
Space : O(20001) ≈ O(1) (constant extra space)

Key Takeaways
-------------
• Always solve the problem correctly before optimizing.
• Remove unnecessary data structures if they are only used once.
• After reducing memory usage, identify the true bottleneck.
• Constraints often reveal opportunities for better algorithms.
• A bounded value range can replace comparison-based sorting with
  frequency counting.

=====================================================================
*/

#include <vector>
#include <algorithm>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// Approach 1 : Sorting + Store Every Pair
/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<vector<int>> temp;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i+=2){
            temp.push_back({nums[i], nums[i+1]});
        }
        int sum = 0;
        for(int j=0; j<temp.size(); j++){
            sum += temp[j][0];
        }
        return sum;
    }
};

/////////////////////////////////////////////////////////////////////////////
// Approach 2 : Sorting + Direct Traversal
/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;                                              //Best one
        for(int i=0; i<nums.size()-1; i+=2){
            sum += nums[i];
        }
        return sum;
    }
};

/////////////////////////////////////////////////////////////////////////////
// Approach 3 : Frequency Array (Counting Sort Simulation)
/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> temp(20001, 0);
        int offset = 10000;
        for(int x=0; x<nums.size(); x++){
            temp[nums[x] + offset]++;
        }
        bool take = true;
        int sum = 0;
        for(int i=0; i<temp.size(); i++){
            for(int j=0; j<temp[i]; j++){
                if(take == 1){
                    sum+=(i-offset);
                }
                take = !take;
            }
        }
        return sum;
    }
};

// Not every problem belongs to exactly one pattern.

// This one can reasonably be tagged as:

// ✅ Sorting
// ✅ Greedy
// ✅ Counting (constraint optimization)