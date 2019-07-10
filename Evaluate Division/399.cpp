/**
* @date: 19-6-4
* @author: fjsxy
* @type: leetcode
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
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
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string,pair<string,double>> father;
        father[equations[0][0]] = make_pair(equations[0][0],1.0);
        father[equations[0][1]] = make_pair(equations[0][0],values[0]);
        for (int i = 1; i < equations.size(); ++i) {
            father[equations[i][1]] = make_pair(father[equations[i][0]].first,)
        }
    }
};

int main() {
    Solution a;
    vector<vector<string>> equtions(2);
    equtions[0] = vector<string>{"a","b"};
    equtions[1] = vector<string>{"b","c"};
    vector<double> value{2.0,3.0};
    vector<vector<string>> quer(5);
    quer[0] = vector<string>{"a","c"};
    quer[1] = vector<string>{"b","a"};
    quer[2] = vector<string>{"a","e"};
    quer[3] = vector<string>{"a","a"};
    quer[4] = vector<string>{"x","x"};
    auto res = a.calcEquation(equtions,value,quer);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
}
