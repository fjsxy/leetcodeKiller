/**
* @date: 19-6-6
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
    int numTrees(int n) {
        if (n == 0)
            return 0;

        vector<int> helpVec(n+1,0);
        helpVec[0] = 1;
        helpVec[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                helpVec[i] += (helpVec[j] * helpVec[i - j - 1]);
            }
        }
        return helpVec[n];
    }
};

int main() {
    Solution a;
    cout << a.numTrees(4) << endl;
}
