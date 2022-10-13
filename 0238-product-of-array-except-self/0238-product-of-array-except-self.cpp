class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
      
      int len = arr.size();
      vector<int> ans(len, 1);
      
      if (len == 0)
        return ans;
      
      
      int left = arr[0], right = arr[len-1];
      
      for (int i = 1 ; i < len ; i++) {
        ans[i] *= left;
        left = left * arr[i];
      }
      
      for (int i = len - 2; i >= 0; i--) {
        ans[i] *= right;
        right = right * arr[i];
      }
      
      return ans;
    }
};