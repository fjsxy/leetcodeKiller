/**
* @date: 19-6-12
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
    void pre(TreeNode* node,vector<TreeNode*>& helpQue)
    {
        if (node == NULL)
            return;

        helpQue.push_back(node);
        pre(node->left,helpQue);
        pre(node->right,helpQue);
    }
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        vector<TreeNode*> help;
        pre(root,help);
        root = help.front();
        for (int i = 0; i < help.size(); ++i) {
            help[i]->left = NULL;
            if (i < help.size() - 1)
                help[i]->right = help[i + 1];
        }
    }
};

int main() {

}
