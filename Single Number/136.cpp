/**
* @date: 19-5-13
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

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            res ^= nums[i];
        }
        return res;
    }
};

int main() {
    vector<int> a{1,1,2,2,3,4,4};
    Solution b;
    cout << b.singleNumber(a) << endl;
    return 0;
}
