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
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;

        int min = prices[0],max = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - min < 0)
                min = prices[i];
            else if(prices[i] - min > max)
                max = prices[i] - min;
        }
        return max;
    }
};

int main() {

}
