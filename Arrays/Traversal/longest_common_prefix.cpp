/*
=====================================================================
                          LeetCode 0014
                     Longest Common Prefix
=====================================================================

Pattern
-------
Traversal

Difficulty
----------
Easy

Problem
-------
Given an array of strings, return the longest common prefix shared
among all the strings. If no common prefix exists, return an empty
string.

Key Insight
-----------
Use the first string as the reference. Compare each character position
with the corresponding character in every other string. The first
mismatch determines where the common prefix ends.

Approach
--------
1. Use the first string as the reference.
2. Traverse each character of the first string.
3. Compare the current character with the character at the same index
   in every other string.
4. If any string ends or a mismatch occurs, return the prefix built so far.
5. Otherwise, append the character to the answer and continue.

Complexity
----------
Time  : O(n × m)
        n = number of strings
        m = length of the shortest common prefix (worst case, first string length)

Space : O(1)
        (Ignoring the output string)

What I Learned
--------------
• Compare character positions instead of comparing strings pairwise.
• The first string can be used as a reference for all comparisons.
• Stop immediately when the first mismatch is encountered.

=====================================================================
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) { 
        string temp = "";
        for(int x=0; x<strs[0].size();x++){
            char ch = strs[0][x];
            for(int y=1; y<strs.size();y++){
                if(x>=strs[y].size() || strs[y][x] != ch){
                    return temp;
                }
            }
            temp += strs[0][x];
        }
        return temp;
    }
};