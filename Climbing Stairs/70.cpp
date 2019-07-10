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
    int climbStairs(int n) {
        if (n == 0)
            return 1;
        vector<int> helpVec(n + 1,1);
        for (int i = 2; i <= n; i++)
        {
            helpVec[i] = helpVec[i - 1] + helpVec[i - 2];
        }
        return helpVec[n];
    }
};

int main() {

}
