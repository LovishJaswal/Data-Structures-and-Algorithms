/*
=====================================================================
                          LeetCode 0904
                     Fruit Into Baskets
=====================================================================

Pattern
-------
Variable Sliding Window + HashMap

Difficulty
----------
Medium

Problem
-------
You are given an integer array fruits where fruits[i] represents the
type of fruit available at the ith tree.

You have two baskets, where each basket can hold only one type of fruit.
Starting from any tree, move to the right collecting exactly one fruit
from every tree until you can no longer collect.

Return the maximum number of fruits that can be collected.

Pattern Recognition
-------------------

Approach
• Expand the window by including fruits[right].
• Store the frequency of each fruit type using a HashMap.
• If more than two distinct fruit types exist,
  continuously shrink the window.
• Remove a fruit type from the map only when its frequency becomes zero.
• After the window becomes valid again,
  update the maximum window length.

Approach Evolution
------------------

Expand Window
↓
More Than 2 Fruit Types?
↓
YES
↓
Shrink Window
↓
Window Valid
↓
Update Maximum Length
↓
Repeat

Complexity
----------

Time  : O(n)
Space : O(1)

(Note:
Although unordered_map is used, the window stores at most
3 distinct fruit types before shrinking and at most 2 afterwards.
Hence the auxiliary space is effectively constant.)

Mistakes I Made
---------------

Mistake 1
• Thought I could directly erase the fruit when moving left.

Wrong

    count.erase(fruits[left]);

Correct

    count[fruits[left]]--;

    if(count[fruits[left]] == 0)
        count.erase(fruits[left]);

Reason:
The same fruit may still exist elsewhere in the current window.

Example

    [2, 1, 2, 3]

Removing the first 2 does not remove all 2's from the window.

-----------------------------------------------------

Mistake 2
• Initially confused window length with number of distinct fruits.

count.size()

=

Number of distinct fruit types.

right - left + 1

=

Current window length.

The answer is always the window length.

-----------------------------------------------------

Mistake 3
• Realized why frequencies are stored instead of only tracking
whether a fruit exists.

Frequency tells us exactly when the last occurrence leaves
the window.

Key Takeaways
-------------
• Store frequencies, not just presence.
• Erase a key only when its frequency becomes zero.
• count.size() gives the number of distinct fruit types.
• right - left + 1 gives the current window length.
• This is the standard "At Most K Distinct" sliding window pattern.

=====================================================================
*/
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int answer = 0;
        unordered_map <int, int> count;
        while(right < fruits.size()){
            count[fruits[right]]++;
            while(count.size()>2){
                count[fruits[left]]--;
                if(count[fruits[left]] == 0){
                    count.erase(fruits[left]);
                }
                left++;
            }
            answer = max(answer, right-left+1);
            right++;
        }
        return answer;
    }
};