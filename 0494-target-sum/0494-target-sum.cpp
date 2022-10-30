class Solution {
public:

    int func(vector<int> &nums, int index, int sum, int target) {
        if (index == nums.size()) {
            if (sum == target)
                return 1;

            return 0;
        }

        return func(nums, index+1, sum + nums[index], target) + func(nums, index+1, sum - nums[index], target);
    
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return func(nums, 0, 0, target);
    }
};