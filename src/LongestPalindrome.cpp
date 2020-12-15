#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <memory>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.length();
        if (len < 2)
            return s;
        for (int i = 0; i < len - 1; i++)
        {
            extendPalindrome(s, i, i);
            extendPalindrome(s, i, i + 1);
        }
        return s.substr(lo, maxLen);
    }

private:
    void extendPalindrome(string s, int j, int k)
    {
        while (j >= 0 && k < s.length() && s[j] == s[k])
        {
            j--;
            k++;
        }
        if (maxLen < k - j - 1)
        {
            lo = j + 1;
            maxLen = k - j - 1;
        }
    }

private:
    int lo, maxLen;
};

int main()
{
    string s = "cbbd";
    Solution solution;

    cout << endl
         << solution.longestPalindrome(s) << endl;
    return 0;
}