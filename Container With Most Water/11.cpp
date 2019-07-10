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
    int maxArea(vector<int>& height) {
        int res = 0;
        int start = 0,end = height.size() - 1;

        while(start <= end)
        {
            res = max(res,min(height[start],height[end]) * (end -start));
            if (height[start] < height[end])
                start++;
            else if (height[start] > height[end])
                end--;
            else
            {
                start++;
                end--;
            }
        }

        return res;
    }
};

int main() {
    Solution a;
    vector<int> input{1,8,6,2,5,4,8,3,7};
    cout << a.maxArea(input) << endl;
}
