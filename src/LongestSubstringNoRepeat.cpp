#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <memory>

using namespace std;

// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int n = s.length();
//         set<char> s_set;
//         // double pointers; sliding window
//         int ans = 0, i = 0, j = 0;
//         while (i < n && j < n)
//         {
//             auto iter = s_set.find(s[j]);
//             if (iter == s_set.end())
//             {
//                 s_set.insert(s[j++]);
//                 ans = max(ans, j - i);
//             }
//             else
//             {
//                 s_set.erase(s_set.find(s[i++]));
//             }
//         }
//         return ans;
//     }
// };

// 02 - optimized sliding window
// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int n = s.length(), ans = 0;
//         unordered_map<char, int> map;
//         for (int j = 0, i = 0; j < n; j++)
//         {
//             if (map.find(s[j]) != map.end())
//             {
//                 i = max(map[s[j]], i);
//             }
//             ans = max(ans, j - i + 1);
//             map[s[j]] = j + 1;
//         }
//         return ans;
//     }
// };

// 03 -
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        const int ASCII_MAX = 255;
        int last[ASCII_MAX];
        int start = 0;

        fill(last, last + ASCII_MAX, -1);
        int max_len = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (last[s[i]] >= start)
            {
                max_len = max(i - start, max_len);
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
        }
        return max((int)s.size() - start, max_len);
    }
};

int main()
{
    string s = "abcabcbb";
    Solution solution;

    cout << solution.lengthOfLongestSubstring(s) << endl;

    return 0;
}