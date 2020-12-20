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
    https://leetcode.com/problems/generate-parentheses/
*/

// not working
/* class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        if (n == 1)
            return {"()"};
        else
        {
            vector<string> temp = generateParenthesis(n - 1);

            for (int j = 0; j < temp.size(); j++)
            {
                res.push_back("()" + temp[j]);
                res.push_back("(" + temp[j] + ")");
                res.push_back(temp[j] + "()");
            }
        }
        set<string> s(res.begin(), res.end());
        res.assign(s.begin(), s.end());
        return res;
    }
}; */

// Use two integers to count the remaining left parenthesis (n) and
// the right parenthesis (m) to be added. At each function call add
// a left parenthesis if n >0 and add a right parenthesis if m>0.
//Append the result and terminate recursive calls when both m and n are zero.
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m)
    {
        if (n == 0 && m == 0)
        {
            v.push_back(str);
            return;
        }
        if (m > 0)
            addingpar(v, str + ")", n, m - 1);
        if (n > 0)
            addingpar(v, str + "(", n - 1, m + 1);
    }
};

int main()
{
    int n = 2;
    Solution solution;
    vector<string> res = solution.generateParenthesis(n);

    for (auto &elem : res)
        cout << elem << " ";

    return 0;
}