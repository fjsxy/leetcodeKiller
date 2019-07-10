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
    vector<int> robWay(TreeNode* root)
    {
        if (root == NULL)
            return vector<int>(2,0);

        vector<int> left = robWay(root->left);
        vector<int> right = robWay(root->right);
        vector<int> res(2,0);
        res[0] = max(left[0],left[1]) + max(right[0],right[1]);//0位表示不包含当前节点情况下的最大值
        res[1] = left[0] + right[0] + root->val;//1位表示包含当前节点情况下的最大值，包含了当前节点，那么该节点的左子节点和右子节点均不可取，所以选择了left0和right0
        return res;
    }
    int rob(TreeNode* root) {
        auto res = robWay(root);
        return max(res[0],res[1]);
    }
};

int main() {

}
