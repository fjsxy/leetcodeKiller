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

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> helpVec1(nums.size()),helpVec2(nums.size());
        helpVec1[0] = 1;
        helpVec2[nums.size() - 1] = 1;
        vector<int> res(nums.size());
        for (int i = 1; i < nums.size(); ++i)
        {
            helpVec1[i] = helpVec1[i - 1] * nums[i - 1];
            helpVec2[nums.size() - 1 - i] = helpVec2[nums.size() - i] * nums[nums.size() - i];
        }

        for (int i = 0; i < res.size(); ++i)
        {
            res[i] = helpVec1[i] * helpVec2[i];
        }
        return res;
    }
};

void print(const int& a)
{
    cout << a << " ";
}

int main() {
    vector<int> b{1,2,3,4};
    Solution a;
    auto res = a.productExceptSelf(b);
    for_each(res.begin(),res.end(),print);
    return 0;
}
