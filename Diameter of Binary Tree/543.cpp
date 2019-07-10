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
    int diameter(TreeNode* node,int& res)
    {
        if (node == NULL)
            return 0;

        int left = diameter(node->left,res);
        int right = diameter(node->right,res);
        res = max(res,left + right);
        return max(left,right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        diameter(root,res);
        return res;
    }
};

int main() {

}
