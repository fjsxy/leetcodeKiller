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
    string decodeString(string s) {
        string res,tmp;
        int markCount = 0,i = s.size() - 1;
        while (i >= 0)
        {
            if (s[i] == '[' )
            {
                markCount--;
            }
            else if (s[i] >= '0' && s[i] < '9')
            {
                string num;
                int j = i;
                while(j >= 0 && s[j] >= '0' && s[j] < '9')
                {
                    num = s[j] + num;
                    j--;
                }
                i = j + 1;
                int count = atoi(num.c_str());
                string ttmp = tmp;
                while (count > 1)
                {
                    tmp = ttmp + tmp;
                    count --;
                }
            }
            else if (s[i] == ']')
            {
                if (markCount == 0)
                {
                    res = tmp + res;
                    tmp = "";
                }
                markCount++;
            }
            else
            {
                tmp = s[i] + tmp;
            }
            if (i == 0)
                res = tmp + res;
            i--;
        }

        return res;
    }
};

int main() {
    Solution a;
    cout << a.decodeString("100[de]") << endl;
    return 0;
}
