/**
* @date: 19-6-13
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

        vector<int> buy(prices.size() + 1,0),sell(prices.size() + 1,0);
        buy[1] = -prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            buy[i + 1] = max(buy[i],sell[i - 1] - prices[i]);
            sell[i + 1] = max(sell[i], buy[i] + prices[i]);
            res = max(buy[i + 1],sell[i + 1]);
        }

        return res;
    }
};

int main() {

}
