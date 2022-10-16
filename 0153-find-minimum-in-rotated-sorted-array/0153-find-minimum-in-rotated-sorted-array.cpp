class Solution {
public:
  
    // Understood the problem
    // Contraints - n <= 5000
    // Edge cases - n == 0 
    // Brute force  - iterate and find
    // Binary search find the pattern
    int findMin(vector<int>& arr) {
        int len = arr.size();
        int first = arr[0], ans = INT_MAX;
        
        int low = 0, high = len - 1, mid;
        
        while (low <= high) {
          mid = low + (high - low)/2;
          
          if (arr[mid] >= first) {
            low = mid + 1;
          } else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
          }
        }
      
      ans = ans == INT_MAX ? arr[0] : ans;
      
      return ans;
    }
};