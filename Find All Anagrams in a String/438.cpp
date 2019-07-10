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
     * 滑窗法
     * 以p的长度为窗口大小，在s中进行滑窗，统计窗口中各个字符的个数，若与p相等则符合条件
     */
    vector<int> findAnagrams(string s, string p) {
        if (s.empty() || p.size() > s.size()) // 匹配字符串长度不能大于被匹配字符串长度
            return vector<int>();
        vector<int> helpVec1(26,0);
        vector<int> helpVec2(26,0);
        vector<int> res;

        for (int i = 0; i < p.size(); ++i) {
            helpVec1[p[i] - 'a']++;
        }
        for (int j = 0; j < p.size(); ++j) {
            helpVec2[s[j] - 'a']++;
        }
        if (helpVec1 == helpVec2)
            res.push_back(0);
        for (int j = 1; j <= s.size() - p.size(); ++j) {
            helpVec2[s[j - 1] - 'a']--;
            helpVec2[s[j + p.size() - 1] - 'a']++;
            if (helpVec1 == helpVec2)
                res.push_back(j);
        }
        return res;
    }
};

int main() {

}
