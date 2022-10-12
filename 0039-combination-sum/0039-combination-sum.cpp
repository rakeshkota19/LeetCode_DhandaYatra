class Solution {
public:
  
  vector<vector<int>> ans;
  void func(int index, vector<int> &arr, int target, vector<int> &current_set) {
    
    if (target < 0)
      return;
    
    if (index == arr.size()) {
      if (target == 0)
        ans.push_back(current_set);
      
      return;
    }
    
    current_set.push_back(arr[index]);
    func(index, arr, target-arr[index], current_set);
    current_set.pop_back();
    
    func(index + 1, arr, target, current_set);
    
  }
  
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        ans.clear();
        vector<int> current_set;
        func(0, arr, target, current_set);
        return ans;
    
    }
};