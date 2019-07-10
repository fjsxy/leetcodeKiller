/**
* @date: 19-5-28
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
    TreeNode* convert(TreeNode* root,int& sum)
    {
        if (root == NULL)
            return root;

        convert(root->right,sum);
        sum += root->val;
        root->val = sum;
        convert(root->left,sum);
    }
    TreeNode* convertBST(TreeNode* root,int& sum) {
        if (root == NULL)
            return root;

        int Sum = 0;
        return convertBST(root->right,sum);
    }
};

int main() {

}
