#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <memory>
#include <chrono>
#include <cassert>
#include <cmath>

using namespace std;

// class Solution
// {
// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         if (nums.size() < 3)
//             return {};
//         vector<vector<int>> res;
//         unordered_map<int, int> map;
//         for (auto i = 0; i < nums.size(); i++)
//             map[-1 * nums[i]] = i;
//         for (auto i = 0; i < nums.size() - 1; i++)
//         {
//             for (auto j = i + 1; j < nums.size(); j++)
//             {
//                 auto iter = map.find(nums[i] + nums[j]);
//                 // this will still have repeated solution (even difference indices)
//                 if (iter != map.end() && iter->second > j)
//                     res.push_back({nums[i], nums[j], -1 * iter->first});
//             }
//         }
//         return res;
//     }
// };

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if ((i > 0) && (nums[i] == nums[i - 1]))
                continue;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                int s = nums[i] + nums[l] + nums[r];
                if (s > 0)
                    r--;
                else if (s < 0)
                    l++;
                else
                {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l + 1 < r && nums[l] == nums[l + 1])
                        l++;
                    while (r - 1 > l && nums[r] == nums[r - 1])
                        r--;
                    l++;
                    r--;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {};
    Solution solution;
    vector<vector<int>> res = solution.threeSum(nums);
    for (auto &vec : res)
    {
        for (auto &i : vec)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}