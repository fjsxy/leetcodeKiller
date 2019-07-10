/**
* @date: 19-6-5
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
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;
        vector<vector<int>> helpVec(grid.size(),vector<int>(grid[0].size(),0));
        helpVec[0][0] = grid[0][0];
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (i == 0 && j > 0)
                    helpVec[i][j] = helpVec[i][j - 1] + grid[i][j];
                else if(j == 0 && i > 0)
                    helpVec[i][j] = helpVec[i - 1][j] + grid[i][j];
                else if(i > 0 && j >0)
                    helpVec[i][j] = min(helpVec[i-1][j],helpVec[i][j-1]) + grid[i][j];
            }
        }
        return helpVec[grid.size() - 1][grid[0].size()-1];
    }
};

int main() {

}
