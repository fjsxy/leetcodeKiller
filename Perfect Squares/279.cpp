/**
* @date: 19-6-25
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
    /*
     * 动态规划
     * 递推式：dp[i + j * j] = min(dp[i + j * j],dp[i] + 1)
     */
    int numSquares(int n) {
        vector<int> dp(n+1,INT32_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; i + j * j <= n ; ++j) {
                dp[i + j * j] = min(dp[i + j * j],dp[i] + 1);
            }
        }
        return dp.back();
    }
    /*
     * 根据四平方和定理，结果就是1，2，3，4中的一个，需要对数字进行简化
     * 四平方和定理
     * 规则1：如果这个数对4取余得0，可以把4除去，不影响结果
     * 规则2：对4取余结束后，如果这个数对8取余得7，则这个数是四个完全平方数的和
     */
    int numSquares2(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int i = 0; i * i <= n ; ++i) {
            int j = static_cast<int>(sqrt(n - i * i));
            if (i*i + j*j == n)
                return (i != 0) + (j != 0);
        }
        return 3;
    }
};

int main() {

}
