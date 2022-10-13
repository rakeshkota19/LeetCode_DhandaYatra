class Solution {
public:
  
    void func(int index, vector<int> &tmp,  vector<int> &nums, vector<vector<int>> &ans) {
      
      if (index == nums.size()) {
        ans.push_back(tmp);
        return;
      }
      
      
      func(index+1, tmp, nums, ans);
      
      tmp.push_back(nums[index]);
      func(index+1, tmp, nums, ans);
      tmp.pop_back();
      return;      
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
      
      vector<int> tmp;
      func(0, tmp, nums, ans);
      return ans;
    }
};