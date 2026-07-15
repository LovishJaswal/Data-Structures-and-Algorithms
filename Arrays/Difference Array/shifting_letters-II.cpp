/*
=====================================================================
                          LeetCode 2381
                      Shifting Letters II
=====================================================================

Pattern
-------
Difference Array

Difficulty
----------
Medium

Problem
-------
You are given a lowercase string s and a list of shift operations.

Each operation is represented as:

    [start, end, direction]

where:
    direction = 1  -> Shift characters forward.
    direction = 0  -> Shift characters backward.

Each operation affects every character in the range
[start, end] (inclusive).

Return the final string after applying all shift operations.

Pattern Recognition
-------------------
• Multiple range updates are performed on the same string.
• Shifting every character for every operation would take O(n × m).
• A Difference Array allows each range shift to be recorded in
  O(1), followed by one Prefix Sum pass to compute the net shift
  for every character.

Algorithm
---------
1. Create a Difference Array of size (n + 1).
2. For every shift operation:
      - If direction == 1:
            diff[left]++
            diff[right + 1]--
      - If direction == 0:
            diff[left]--
            diff[right + 1]++
3. Compute the Prefix Sum to obtain the net shift at every index.
4. Convert each character into the range [0, 25].
5. Apply the accumulated shift using modulo 26.
6. Convert the value back into a character and build the answer.

Complexity
----------
Range Updates : O(m)
Prefix Sum    : O(n)
Space         : O(n)

where:
    m = number of shift operations
    n = length of the string

Key Takeaways
-------------
• Difference Arrays efficiently handle multiple range updates.
• Since the range is inclusive:
      diff[left]      += value
      diff[right + 1] -= value
• Store only the net shifts in the Difference Array—not the
  characters themselves.
• One Prefix Sum reconstructs the total shift for every index.
• Characters wrap around cyclically, so modulo 26 is required.

What I Learned
--------------
• The Difference Array should represent the quantity being updated.
  Here, that quantity is the shift amount—not the characters.
• Keep the original string unchanged and apply the final shift only
  after computing the Prefix Sum.
• Converting characters to the range [0, 25] makes circular
  shifting much easier than working directly with ASCII values.
• C++ returns negative values for the modulo operator, so normalize
  using:
      ((x % 26) + 26) % 26
• The expression

      'a' + ((s[i] - 'a' + shift) % 26 + 26) % 26

  performs four steps:
      1. Convert character to [0, 25].
      2. Apply the accumulated shift.
      3. Wrap using modulo 26.
      4. Convert back to a character.

=====================================================================
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        string answer;

        vector<int> temp(s.size() + 1, 0);

        for (int i = 0; i < shifts.size(); i++) {

            if (shifts[i][2] == 0) {
                temp[shifts[i][0]]--;
                temp[shifts[i][1] + 1]++;
            }
            else {
                temp[shifts[i][0]]++;
                temp[shifts[i][1] + 1]--;
            }

        }

        temp.pop_back();

        int sum = 0;

        for (int j = 0; j < temp.size(); j++) {

            temp[j] += sum;
            sum = temp[j];

            answer += char('a' + ((s[j] - 'a' + temp[j]) % 26 + 26) % 26);

        }

        return answer;
    }
};