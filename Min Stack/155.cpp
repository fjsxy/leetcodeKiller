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

class MinStack {
public:
/** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (helpStack2.empty() || x <= helpStack2.top())
            helpStack2.push(x);
        helpStack.push(x);
    }

    void pop() {
        if (helpStack.top() == helpStack2.top())
            helpStack2.pop();
        helpStack.pop();
    }

    int top() {
        return helpStack.top();
    }

    int getMin() {
        return helpStack2.top();
    }

private:
    stack<int> helpStack;
    stack<int> helpStack2;
};

int main() {

}
