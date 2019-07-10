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

class Solution {//递归比较
public:
    bool isSym(TreeNode* node1,TreeNode* node2)
    {
        if (node1 == NULL && node2 == NULL)
            return true;
        if (node1 == NULL || node2 == NULL || node1->val != node2->val)
            return false;

        return isSym(node1->left,node2->right) && isSym(node1->right,node2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return isSym(root->left,root->right);
    }
};

class Solution2 {//双队列层序遍历迭代
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        bool res = true;
        queue<TreeNode*> que1,que2;
        que1.push(root->left);
        que2.push(root->right);
        bool isOver = false;
        while (!que1.empty() && !que2.empty())
        {
            TreeNode* tmp1 = que1.front();
            TreeNode* tmp2 = que2.front();
            que1.pop();
            que2.pop();
            if (tmp1 == NULL && tmp2 == NULL)
                continue;
            if (tmp1 == NULL || tmp2 == NULL || tmp1->val != tmp2->val)
            {
                res = false;
                break;
            }
            que1.push(tmp1->left);
            que1.push(tmp1->right);
            que2.push(tmp2->right);
            que2.push(tmp2->left);
        }
        return res;
    }
};

int main() {

}
