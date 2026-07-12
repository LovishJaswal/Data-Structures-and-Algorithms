/*
=====================================================================
                          LeetCode 0125
                         Valid Palindrome
=====================================================================

Pattern
-------
Two Pointers

Difficulty
----------
Easy

Problem
-------
Given a string s, determine whether it is a palindrome after
converting all uppercase letters to lowercase and removing all
non-alphanumeric characters.

Pattern Recognition
-------------------
• The comparison must be made from both ends of the string.
• Only alphanumeric characters are considered.
• Preprocessing the string allows a simple two-pointer traversal.

Algorithm
---------
1. Create a new string containing only lowercase alphanumeric
   characters.
2. Initialize two pointers:
      - left at the beginning.
      - right at the end.
3. Compare the characters at both pointers.
4. If they match, move both pointers inward.
5. If they do not match, return false.
6. If all characters match, return true.

Complexity
----------
Time  : O(n)
Space : O(n)

What I Learned
--------------
• Two pointers are useful for comparing symmetric elements.
• Preprocessing can simplify the implementation.
• isalnum() filters valid characters.
• tolower() enables case-insensitive comparison.

=====================================================================
*/

#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        string filtered;

        for (char character : s) {
            if (isalnum(character)) {
                filtered += tolower(character);
            }
        }

        int left = 0;
        int right = filtered.size() - 1;

        while (left < right) {

            if (filtered[left] == filtered[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }

        return true;
    }
};