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
    void Count(const string& s, int i1,int i2, int &res)
    {
        int i = i1,j = i2;
        while (i >= 0 && j < s.size() && s[i] == s[j])
        {
            --i;
            ++j;
            ++res;
        }
    }
    int countSubstrings(string s) {
        int res = 0;
        if (s.empty())
            return res;

        for (int i = 0; i < s.size(); ++i)
        {
            Count(s,i,i,res);
            Count(s,i,i+1,res);
        }

        return res;
    }
};

int main() {
    Solution a;
    string s = "a";
    cout << a.countSubstrings(s) << endl;

}
