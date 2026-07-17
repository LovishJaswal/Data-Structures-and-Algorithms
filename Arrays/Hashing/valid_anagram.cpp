/*
=====================================================================
                          LeetCode 0242
                           Valid Anagram
=====================================================================

Pattern
-------
Hashing (Frequency Counting)

Difficulty
----------
Easy

Problem
-------
Given two strings s and t, return true if t is an anagram of s,
and false otherwise.

An anagram is a word formed by rearranging the letters of another
word using exactly the same characters and frequencies.

Pattern Recognition
-------------------

Approach 1
• Use an unordered_map to store the frequency of every character.
• Traverse string s and increment the frequency of each character.
• Traverse string t and decrement the frequency of each character.
• If every frequency becomes zero, the strings are anagrams.
• Otherwise, they are not.

Approach 2
• Since the strings contain only lowercase English letters,
  use a frequency array of size 26 instead of a hash map.
• Traverse both strings simultaneously.
• Increment the frequency for characters in s.
• Decrement the frequency for characters in t.
• If every index becomes zero, the strings are anagrams.

Approach Evolution
------------------

Approach 1
HashMap
↓
Count Characters in s
↓
Subtract Characters in t
↓
Check All Frequencies
↓
Answer

Approach 2
Frequency Array (26)
↓
Count & Subtract Simultaneously
↓
Check All Frequencies
↓
Answer

Complexity
----------

Approach 1
Time  : O(n)
Space : O(k)
(k = number of distinct characters)

Approach 2
Time  : O(n)
Space : O(1)

Key Takeaways
-------------
• Hashing is useful when frequency information is required.
• A single HashMap can both count and cancel frequencies.
• Always check string lengths first because different lengths
  can never form anagrams.
• When the character set is fixed (26 lowercase letters),
  a frequency array is faster and uses constant space.

=====================================================================
*/

#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// Approach 1 : HashMap Frequency Counting
/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> freq;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }

        for (int j = 0; j < t.size(); j++) {
            freq[t[j]]--;
        }

        for (auto it : freq) {
            if (it.second != 0) {
                return false;
            }
        }

        return true;
    }
};

/////////////////////////////////////////////////////////////////////////////
// Approach 2 : Frequency Array
/////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size()) {
            return false;
        }

        vector<int> temp(26, 0);

        for (int i = 0; i < s.size(); i++) {
            temp[s[i] - 'a']++;
            temp[t[i] - 'a']--;
        }

        for (auto it : temp) {
            if (it != 0) {
                return false;
            }
        }

        return true;
    }
};