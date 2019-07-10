/**
* @date: 19-5-30
* @author: fjsxy
* @type: leetcode
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> helpVec(n,vector<int>(m,1));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (i == 0 || j == 0)
                    helpVec[i][j] = 1;
                else
                {
                    helpVec[i][j] = helpVec[i][j -1] + helpVec[i - 1][j];
                }
            }
        }

        return helpVec[n - 1][m - 1];
    }
};

int main() {
    Solution a;
    cout << a.uniquePaths(7,3) << endl;
}
