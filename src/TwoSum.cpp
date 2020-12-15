// CodeDaily.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dic;
        vector<int> res;
        for (auto i = 0; i < nums.size(); ++i) {
            dic[target - nums[i]] = i;
        }
        for (auto i = 0; i < nums.size(); ++i) {
            auto index = dic.find(nums[i]);
            if (index != dic.end() && index->second != i) {
                return {i, index->second};
            }
        }
        return res;
    }
};

int main() {

    Solution solution;
    vector<int> nums{2,7,11,15};
    int target = 9;

    auto res = solution.twoSum(nums, target);

    for (auto& i: res) {
        cout << i << " ";
    }

    return 0;
}
