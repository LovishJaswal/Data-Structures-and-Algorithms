/*
=====================================================================
                          LeetCode 0059
                        Spiral Matrix II
=====================================================================

Pattern
-------
Simulation

Difficulty
----------
Medium

Problem
-------
Given a positive integer n, generate an n × n matrix filled with
elements from 1 to n² in spiral order.

Key Insight
-----------
Instead of reading elements in spiral order, simulate the spiral
movement while filling the matrix. Maintain four boundaries to
represent the current unfilled region.

Approach
--------
1. Create an n × n matrix initialized with zeros.
2. Initialize four boundaries: top, bottom, left, and right.
3. Start filling from the top-left corner with the value 1.
4. Traverse:
   - Left to Right
   - Top to Bottom
   - Right to Left
   - Bottom to Top
5. After each traversal, shrink the corresponding boundary.
6. Continue until all layers of the matrix are filled.

Complexity
----------
Time  : O(n²)
Space : O(1) (excluding the output matrix)

What I Learned
--------------
• Matrix generation problems can be solved using the same boundary
  simulation used in Spiral Matrix traversal.
• Four boundaries (top, bottom, left, right) help manage each spiral
  layer cleanly.
• Boundary checks prevent revisiting cells when only one row or one
  column remains.
• Simulation can be used not only to traverse a matrix but also to
  construct one.

=====================================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> answer(n, vector<int>(n));
        int i=0,j =0;
        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;
        answer[0][0] = 1;
        int it = 2;
        while(top<=bottom && left<=right){
            while(j<right){
                j++;
                answer[i][j] = it;
                it++;
            }
            top++;
            if(top>bottom){
                break;
            }
            while(i<bottom){
                i++;
                answer[i][j] = it;
                it++;
            }
            right--;
            if(right < left){
                break;
            }
            while(j>left){
                j--;
                answer[i][j] = it;
                it++;
            }
            bottom--;
            if(top>bottom){
                break;
            }
            while(i>top){
                i--;
                answer[i][j] = it;
                it++;
            }
            left++;
        }
    return answer;
    }
};