/*
=====================================================================
                          LeetCode 0054
                         Spiral Matrix
=====================================================================

Pattern
-------
Simulation

Difficulty
----------
Medium

Problem
-------
Given an m × n matrix, return all elements of the matrix in spiral
order, starting from the top-left corner and moving clockwise.

Key Insight
-----------
Maintain four boundaries (top, bottom, left, and right) to represent
the current unvisited portion of the matrix. Traverse one side at a
time and shrink the corresponding boundary after completing each
direction.

Approach
--------
1. Initialize four boundaries: top, bottom, left, and right.
2. Start from the top-left element and add it to the answer.
3. Traverse:
   - Left to Right
   - Top to Bottom
   - Right to Left
   - Bottom to Top
4. After completing each traversal, update the corresponding boundary.
5. Repeat until all boundaries cross each other.

Complexity
----------
Time  : O(m × n)
Space : O(1) (excluding the output vector)

What I Learned
--------------
• Simulation becomes easier by maintaining four boundaries instead of
  tracking visited cells.
• Update boundaries only after completing the corresponding traversal.
• Boundary checks are necessary to handle matrices with a single
  remaining row or column.
• Matrix traversal problems often require careful index management to
  avoid out-of-bounds access.

=====================================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> answer;
        int i=0,j =0;
        int left = 0;
        int right = matrix[0].size()-1;
        int top = 0;
        int bottom = matrix.size()-1;
        answer.push_back(matrix[0][0]);
        while(top<=bottom && left<=right){
            while(j<right){
                j++;
                answer.push_back(matrix[i][j]);
            }
            top++;
            if(top>bottom){
                break;
            }
            while(i<bottom){
                i++;
                answer.push_back(matrix[i][j]);
            }
            right--;
            if(right < left){
                break;
            }
            while(j>left){
                j--;
                answer.push_back(matrix[i][j]);
            }
            bottom--;
            if(top>bottom){
                break;
            }
            while(i>top){
                i--;
                answer.push_back(matrix[i][j]);
            }
            left++;
        }
    return answer;
    }
};