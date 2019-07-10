/**
* @date: 19-5-29
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        queue<TreeNode*> helpQue;
        helpQue.push(root);
        vector<int> tmpVec;
        int count = 1,nextCount = 0;
        while(!helpQue.empty())
        {
            TreeNode* p = helpQue.front();
            helpQue.pop();
            tmpVec.emplace_back(p->val);
            count--;
            if (p->left)
            {
                helpQue.push(p->left);
                nextCount++;
            }
            if (p->right)
            {
                helpQue.push(p->right);
                nextCount++;
            }
            if (count == 0)
            {
                count = nextCount;
                nextCount = 0;
                res.emplace_back(tmpVec);
                tmpVec.clear();
            }
        }
        return res;
    }
};

int main() {

}
