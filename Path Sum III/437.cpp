/**
* @date: 19-6-10
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
    void DFS(TreeNode* root,int sum,int curSum, int& res,vector<TreeNode*> &help)
    {
        if (root == NULL)
            return;

        curSum += root->val;
        if (curSum == sum) res++;
        help.push_back(root);

        int tmp = curSum;
        for (int i = 0; i < help.size() - 1; ++i)
        {
            tmp = tmp - help[i]->val;
            if (tmp == sum) res++;
        }

        DFS(root->left,sum,curSum,res,help);
        DFS(root->right,sum,curSum,res,help);

        help.pop_back();
    }
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        vector<TreeNode*> help;
        DFS(root,sum,0,res,help);
        return res;
    }
};

int main() {
    Solution a;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(-2);
    root->right = new TreeNode(-3);
    cout << a.pathSum(root,-1) << endl;
    return 0;
}
