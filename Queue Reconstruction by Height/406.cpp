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
    static bool cmp(const vector<int>& v1,const vector<int>& v2)
    {
        if (v1[0] > v2[0])
            return true;
        else if (v1[0] == v2[0])
            return v1[1] < v2[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<vector<int>> res(people.size());

        for (int i = 0; i < people.size(); ++i)
        {
            res.insert(res.begin() + people[i][1],people[i]);
        }

        return res;
    }
};

void print(const vector<int>& a)
{
    cout << a[0] << "," << a[1] << endl;
}

int main() {
    Solution a;
    vector<vector<int>> b{{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    auto c = a.reconstructQueue(b);
    for_each(c.begin(),c.end() - 1,print);
    return 0;
}
