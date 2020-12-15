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

TODO class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.empty())
            return {};
        sort(nums.begin(), nums.end());
    }
};

int main()
{
    vector<int> nums{1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution solution;
    vector<vector<int>> res = solution.fourSum(nums, target);
    // vector<vector<int>> res{
    //     {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
    for (auto &row : res)
    {
        for (auto &i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}