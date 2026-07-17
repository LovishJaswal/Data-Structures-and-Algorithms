/*
=====================================================================
                          LeetCode 0049
                           Group Anagrams
=====================================================================

Pattern
-------
Hashing (Grouping)

Difficulty
----------
Medium

Problem
-------
Given an array of strings strs, group the anagrams together.

Two strings are anagrams if they contain exactly the same
characters with the same frequencies, regardless of order.

Return the grouped anagrams in any order.

Pattern Recognition
-------------------

Approach 1
• Traverse every string in the array.
• Create a copy of the current string.
• Sort the copied string to obtain a canonical representation.
• Use the sorted string as the key in an unordered_map.
• Store the original string inside the vector corresponding to that key.
• Finally, traverse the HashMap and collect all grouped anagrams.

Approach Evolution
------------------

Original String
↓
Sort Copy
↓
Generate Key
↓
HashMap
(Key → Vector of Strings)
↓
Answer

Complexity
----------

Approach 1
Time  : O(n × k log k)

where
n = number of strings
k = average length of each string

Space : O(n × k)

Key Takeaways
-------------
• HashMaps can store containers as values.
• Different strings can map to the same key.
• Sorting each string creates a unique canonical form for
  every anagram group.
• Store the original string while using the sorted string
  only as the HashMap key.

=====================================================================
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
// Approach 1 : HashMap + Sorted String Key
/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> answer;
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {

            string key = strs[i];
            sort(key.begin(), key.end());

            mp[key].push_back(strs[i]);
        }

        for (auto it : mp) {
            answer.push_back(it.second);
        }

        return answer;
    }
};