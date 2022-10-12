class Solution {
public:
  
    void func(int index, vector<int> &arr , vector<int> &tmp, vector<vector<int>> &ans) {
      
      if (index >= 22) {
        return;
      } 
  
      if (index == 21) {
        ans.push_back(tmp);
        return;
      }
  
      
      
      if (arr[index] > 0) {
        arr[index]--;
        tmp.push_back(index - 10);
        func(index, arr, tmp, ans);
        tmp.pop_back();
        arr[index]++;

      }
      
      func(index+1, arr, tmp, ans);

    
      return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      
      vector<vector<int>> ans;        
        
      // as -10 <= nums[i] <= 10, i.e at max 21 elements ( 0..20)  
      
      vector<int> arr(21, 0);
      
      for(int i = 0 ; i < nums.size() ; i++) {
        arr[nums[i] + 10]++;
      }      
      
      
      vector<int> tmp;
      func(0, arr, tmp, ans);
      return ans;  
    }
};