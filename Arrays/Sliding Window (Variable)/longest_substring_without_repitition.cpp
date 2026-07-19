/*
=====================================================================
                          LeetCode 0003
          Longest Substring Without Repeating Characters
=====================================================================

Pattern
-------
Variable Sliding Window + HashMap

Difficulty
----------
Medium

Problem
-------
Given a string s, find the length of the longest substring
without repeating characters.

Pattern Recognition
-------------------

Approach 1 (Initial Thought Process)
• Expand the window by inserting the current character.
• If a duplicate appears, shrink the window until it becomes valid.
• Initially tried updating the answer using freq.size().
• Also updated the answer while the window was still invalid.
• The shrinking logic was correct, but the answer was calculated
  at the wrong time and using the wrong value.

Approach 2 (Standard Variable Sliding Window)
• Expand the window by including s[right].
• If the current character becomes duplicated, shrink the window
  until the duplicate is removed.
• Once the window is valid again, update the maximum window length.
• Every character enters and leaves the window at most once.

Approach Evolution
------------------

Approach 1

Expand
↓
Duplicate Found
↓
Update Answer ❌
↓
Shrink

Approach 2

Expand
↓
Duplicate Found
↓
Shrink Until Valid
↓
Update Answer ✅

Complexity
----------

Approach 1
Time  : O(n)
Space : O(min(n, charset))

Approach 2
Time  : O(n)
Space : O(min(n, charset))

Mistakes I Made
---------------

Mistake 1
• Used freq.size() as the answer.

Example

Window = "abcdef"

freq.size() = 6
Window Length = 6

Looks correct.

But the problem asks for the length of the current window,
which is always:

    right - left + 1

The answer is NOT the number of distinct characters.

-----------------------------------------------------

Mistake 2
• Updated the answer while the window was still invalid.

Wrong

    Expand
    ↓
    Duplicate
    ↓
    Update Answer
    ↓
    Shrink

Correct

    Expand
    ↓
    Duplicate
    ↓
    Shrink Until Valid
    ↓
    Update Answer

-----------------------------------------------------

Mistake 3
• Forgot the difference between Minimum Window and Maximum Window.

Minimum Window (209)

    Add
    ↓
    Window Valid
    ↓
    Update
    ↓
    Shrink

Maximum Window (3)

    Add
    ↓
    Window Invalid
    ↓
    Shrink
    ↓
    Update

-----------------------------------------------------

Mistake 4
• Added unnecessary edge-case checks for
  s.size() == 0 and s.size() == 1.

The sliding window itself already handles both cases correctly.

Key Takeaways
-------------
• Update the answer only after the window becomes valid.
• The answer is the current window length, not freq.size().
• unordered_map::size() represents the number of distinct keys,
  not the window length.
• Remove keys from the map when their frequency becomes zero,
  otherwise freq.size() becomes incorrect for distinct-count problems.
• For maximum window problems, the standard template is:

      Add
      ↓
      While Window Invalid
      ↓
      Remove
      ↓
      Update Answer

=====================================================================
*/

#include <unordered_map>
#include <string>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// Standard Variable Sliding Window
/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0;
        int right = 0;
        int answer = 0;

        unordered_map<char, int> freq;

        while (right < s.size()) {

            freq[s[right]]++;

            while (freq[s[right]] > 1) {

                freq[s[left]]--;

                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }

                left++;
            }

            answer = max(answer, right - left + 1);

            right++;
        }

        return answer;
    }
};