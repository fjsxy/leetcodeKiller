/**
* @date: 19-5-15
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

class Solution {// 中序遍历递归
public:
    void inorder(TreeNode* root,vector<int>& res)
    {
        if(root != NULL)
        {
            inorder(root->left,res);
            res.push_back(root->val);
            inorder(root->right,res);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};

class Solution2{// 中序遍历非递归
public:
    vector<int> inorderTraversal(TreeNode* root){
        if (root == NULL)
            return vector<int>();

        vector<int> res;
        stack<TreeNode*> helpStack;
        helpStack.push(root);
        while(!helpStack.empty())
        {
            TreeNode* tmp = helpStack.top();
            if (tmp->left)
            {
                helpStack.push(tmp->left);
                tmp->left = NULL;
                continue;
            }
            else if (tmp->right)
            {
                res.push_back(tmp->val);
                helpStack.pop();
                helpStack.push(tmp->right);
            }
            else
            {
                res.push_back(tmp->val);
                helpStack.pop();
            }
        }

        return res;
    }
};

void print(const int& a)
{
    cout << a << " ";
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    Solution2 a;
    auto res = a.inorderTraversal(root);
    for_each(res.begin(),res.end(),print);
    return 0;
}
