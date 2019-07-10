/**
* @date: 19-6-26
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
    void dfs(vector<vector<char>>& grid,int i,int j){ // 将一个岛屿的1递归地变成0
        grid[i][j] = '0';
        for (auto &it : haha)
        {
            int x = i + it.first;
            int y = j + it.second;
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == '1')
                dfs(grid,x,y);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int n = grid[0].size();
        int m = grid.size();
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1')
                {
                    res++;
                    dfs(grid,i,j);// 直到将一个岛屿的全部1都变成0之后才退出，寻找下一个1的位置
                }
            }
        }
        return res;
    }

private:
    vector<pair<int,int>> haha{{-1,0},{0,1},{1,0},{0,-1}};
};

int main() {

}
