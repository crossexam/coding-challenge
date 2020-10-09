/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> m;
        int s = nums.size();
        for (int i = 0; i < s; i++) {
            if (m.count(target-nums[i])) {
                ans.push_back(m[target-nums[i]]);
                ans.push_back(i);
                break;
            } else {
                m.insert({nums[i],i});
            }
        }
        return ans;
    }
};
