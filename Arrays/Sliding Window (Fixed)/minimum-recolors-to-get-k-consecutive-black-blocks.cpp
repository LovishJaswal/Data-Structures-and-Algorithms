/*
=====================================================================
                          LeetCode 2379
          Minimum Recolors to Get K Consecutive Black Blocks
=====================================================================

Pattern
-------
Sliding Window (Fixed)

Difficulty
----------
Easy

Problem
-------
You are given a string blocks consisting of black ('B') and white ('W')
blocks, along with an integer k.

In one operation, you can recolor one white block into a black block.

Return the minimum number of operations needed so that there exists at
least one substring of length k containing only black blocks.

Key Insight
-----------
The number of operations required for a window is exactly the number of
white blocks ('W') in that window. Find the window of size k with the
minimum number of white blocks.

Approach
--------
1. Count the number of white blocks in the first window of size k.
2. Store this count as the current minimum.
3. Slide the window one position at a time:
   - Add 1 if the incoming block is white.
   - Subtract 1 if the outgoing block is white.
4. Update the minimum count after each slide.
5. Return the minimum number of operations.

Complexity
----------
Time  : O(n)
Space : O(1)

What I Learned
--------------
• A fixed-size sliding window can maintain counts in constant time.
• Sometimes the required answer is simply the count of a specific
  character within each window.
• Instead of checking every window from scratch, update only what
  changes when the window slides.

=====================================================================
*/

#include <string>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int answer = 0;
        int operations = 0;
        for(int i=0; i<k; i++){
            if(blocks[i] == 'W')
                operations += 1;
        }
        answer = operations;
        for(int j=k; j<blocks.size(); j++){
            if(blocks[j] == 'W'){
                operations++;
            }
            if(blocks[j-k] == 'W'){
                operations--;
            }
            answer = min(answer, operations);
        }
        return answer;
    }
};