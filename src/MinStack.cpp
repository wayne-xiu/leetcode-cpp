#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <set>
#include <memory>
#include <chrono>
#include <cassert>
#include <cmath>
#include <stack>
#include <array>

using namespace std;

/* Problem link:
    https://leetcode.com/problems/min-stack/
*/

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        dataStack.push(x);
        if (minStack.empty())
            minStack.push(x);
        else
            minStack.push(min(minStack.top(), x));
    }

    void pop()
    {
        dataStack.pop();
        minStack.pop();
    }

    int top()
    {
        return dataStack.top();
    }

    int getMin()
    {
        return minStack.top();
    }

private:
    stack<int> dataStack;
    stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    cout << minStack->getMin() << endl;
    minStack->pop();
    cout << minStack->top() << endl;
    cout << minStack->getMin() << endl;
    return 0;
}