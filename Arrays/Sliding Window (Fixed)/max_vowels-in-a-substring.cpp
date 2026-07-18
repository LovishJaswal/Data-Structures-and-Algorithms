/*
=====================================================================
                          LeetCode 1456
           Maximum Number of Vowels in a Substring of Given Length
=====================================================================

Pattern
-------
Sliding Window (Fixed)

Difficulty
----------
Medium

Problem
-------
Given a string s and an integer k, return the maximum number of vowels
in any substring of s with length k.

Key Insight
-----------
Since the window size is fixed, keep track of the number of vowels in
the current window. As the window slides, only the incoming and
outgoing characters affect the vowel count.

Approach
--------
1. Count the vowels in the first window of size k.
2. Store this count as the current maximum.
3. Slide the window one character at a time:
   - Add the incoming character if it is a vowel.
   - Remove the outgoing character if it is a vowel.
4. Update the maximum vowel count after each slide.
5. Return the maximum vowel count found.

Complexity
----------
Time  : O(n)
Space : O(1)

What I Learned
--------------
• A fixed-size sliding window allows constant-time updates.
• Only two characters change when the window moves.
• Maintain a running count instead of recounting each window.
• Update the answer after every window shift.

=====================================================================
*/

#include <string>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int answer = 0;
        int vowels_cnt = 0;
        for(int i=0; i<k; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                vowels_cnt += 1; 
            }
        }
        answer = vowels_cnt;
        for(int j=k; j<s.size(); j++){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u'){
                vowels_cnt += 1;
            }
            if(s[j-k] == 'a' || s[j-k] == 'e' || s[j-k] == 'i' || s[j-k] == 'o' || s[j-k] == 'u'){
                vowels_cnt -= 1;
            }
            answer = max(answer, vowels_cnt);
        }
        return answer;
    }
};