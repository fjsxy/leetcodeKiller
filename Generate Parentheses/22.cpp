/**
* @date: 19-5-20
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
    void generate(int left,int right,string output,vector<string>& res)
    {
        if (left > right)
            return;
        else if (left == 0 && right == 0)
            res.emplace_back(output);
        else
        {
            if (left > 0)
                generate(left - 1,right,output + '(',res);
            if (right > 0)
                generate(left,right - 1,output + ')',res);
        }
    }
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return vector<string>();

        vector<string> res;
        string output;
        generate(n,n,output,res);

        return res;
    }
};

void print(const string& a)
{
    cout << a << endl;
}

int main() {
    Solution a;
    auto res = a.generateParenthesis(3);
    for_each(res.begin(),res.end(),print);
    return 0;
}
