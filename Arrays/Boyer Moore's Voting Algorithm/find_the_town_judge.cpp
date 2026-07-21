/*
=====================================================================
                          LeetCode 0997
                     Find the Town Judge
=====================================================================

Pattern
-------
Counting

Difficulty
----------
Easy

Problem
-------
In a town of n people labeled from 1 to n, there is a rumor
that one of these people is secretly the town judge.

If the town judge exists, then:

• The judge trusts nobody.
• Everybody except the judge trusts the judge.
• There is exactly one person satisfying both conditions.

Return the label of the town judge if the judge exists,
otherwise return -1.

Pattern Recognition
-------------------
Ask yourself:

• Do I need to know how many people trust each person?
• Do I need to know how many people each person trusts?
• Can I solve this by counting instead of traversing a graph?

If YES, counting incoming and outgoing trust is the
optimal solution.

Approach
--------
• Create one array to count how many people each person trusts.
• Create another array to count how many people trust each person.
• Traverse every trust relationship once and update both arrays.
• Traverse all people.
• The judge is the person who:
    - Trusts nobody.
    - Is trusted by every other person.

Approach Evolution
------------------

Initialize Two Count Arrays
↓
Traverse Trust Relationships
↓
Increment:
    Trusts[a]
    TrustedBy[b]
↓
Traverse All People
↓
Trusts == 0 ?
        AND
TrustedBy == n - 1 ?
↓
Return Judge
↓
Otherwise Return -1

Key Observation
---------------
The judge has:

• Outgoing Trust = 0
• Incoming Trust = n - 1

Instead of storing who trusts whom,
only store the number of incoming and outgoing
trust relationships for each person.

Complexity
----------

Time  : O(n + m)
        m = trust.size()

Space : O(n)

*/

#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n + 1, 0);
        vector<int> trusted_by(n + 1, 0);

        for (int i = 0; i < trust.size(); i++) {
            trusts[trust[i][0]]++;
            trusted_by[trust[i][1]]++;
        }

        for (int j = 1; j <= n; j++) {
            if (trusts[j] == 0 && trusted_by[j] == trusts.size() - 2) {
                return j;
            }
        }

        return -1;
    }
};