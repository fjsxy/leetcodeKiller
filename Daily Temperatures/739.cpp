/**
* @date: 19-5-14
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
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty())
            return vector<int>();
        vector<int> res(T.size(),0);
        stack<pair<int,int>> help_stack;

        for (int i = 0; i < T.size(); ++i) {
            while (!help_stack.empty() && T[i] > help_stack.top().second)
            {
                res[help_stack.top().first] = i - help_stack.top().first;
                help_stack.pop();
            }
            help_stack.push(make_pair(i,T[i]));
        }
        return res;
    }
};

void print(int n)
{
    cout << n << " ";
}

int main() {
    Solution a;
    vector<int> b{73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = a.dailyTemperatures(b);
    for_each(res.begin(),res.end(),print);
    return 0;
}
