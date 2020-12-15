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

using namespace std;

// class Solution
// {
// public:
//     bool isValid(string s)
//     {
//         stack<char> st;
//         for (auto i = 0; i < s.length(); i++)
//         {
//             if (s[i] == '(')
//                 st.push(')');
//             else if (s[i] == '[')
//                 st.push(']');
//             else if (s[i] == '{')
//                 st.push('}');
//             else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
//             {
//                 if (st.empty())
//                     return false;
//                 if (s[i] == st.top())
//                     st.pop();
//                 else
//                     return false;
//             }
//         }
//         return st.empty();
//     }
// };

// elegant solution

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        map<char, char> mp = createMap();
        for (auto i : s)
        {
            if (st.empty())
                st.push(i);
            else
            {
                if (mp[st.top()] == i)
                    st.pop();
                else
                    st.push(i);
            }
        }
        return st.empty();
    }
    map<char, char> createMap()
    {
        map<char, char> mp;
        mp['{'] = '}';
        mp['('] = ')';
        mp['['] = ']';
        return mp;
    }
};

int main()
{
    string in = "[]";
    Solution solution;
    cout << "Valid Parentheses: " << solution.isValid(in) << endl;
    return 0;
}