/*
=====================================================================
                          LeetCode 0682
                         Baseball Game
=====================================================================

Pattern
-------
Simulation

Difficulty
----------
Easy

Problem
-------
You are given a list of operations representing the scoring rules of a
baseball game. Maintain a record of scores by applying each operation
in order and return the sum of all valid scores.

Key Insight
-----------
Maintain the score history in a dynamic array and simulate each
operation exactly as described. Every new operation depends only on
the current state of the record.

Approach
--------
1. Create a vector to store all valid scores.
2. Traverse each operation in the given order.
3. Perform the corresponding action:
   - "C" : Remove the previous score.
   - "D" : Add double of the previous score.
   - "+" : Add the sum of the previous two scores.
   - Integer : Convert the string to an integer using stoi() and add it.
4. Traverse the score record and compute the final sum.

Complexity
----------
Time  : O(n)
Space : O(n)

What I Learned
--------------
• Simulation problems require maintaining the current state after every
  operation.
• vector can efficiently simulate the score record using push_back()
  and pop_back().
• back() and size() help access the most recent scores.
• stoi() converts numeric strings into integers when processing input.

=====================================================================
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector <int> temp;
        for (string op : operations) {

            if (op == "C") {
                temp.pop_back();
            }
            else if (op == "D") {
                temp.push_back(2*(temp[temp.size()-1]));
            }
            else if (op == "+") {
                temp.push_back((temp[temp.size()-1])+(temp[temp.size()-2]));
            }
            else {
                int num = stoi(op);
                temp.push_back(num);
            }
        }
        int ans = 0;
        for(int i=0; i<temp.size();i++){
            ans += temp[i];
        }
        return ans;
    }
};