class Solution {
public:
  
    // understand the problem - done
    // constraints - 10pow4 , both positive and negative elements
    // edge casses - all positive all negative
    // B.F - square all elements, sort them - O(nlogn)
    // Take new array, add eleements to it like merging 2 lists - O(n) spce O(n)
    
    
    vector<int> sortedSquares(vector<int>& arr) {
        int len = arr.size();
        int positive = len;
        
        for (int i = 0 ; i < len ; i++) {
          if (arr[i] >= 0) {
            positive = i;
            break;
          } 
        }
      
        vector<int> ans;
        int i = positive - 1, j = positive;
        while (i >= 0 && j < len) {
          
            if (abs(arr[i]) > arr[j]) {
              ans.push_back(arr[j] * arr[j]);
              j++;
            } else {
              ans.push_back(abs(arr[i] * arr[i]));
              i--;
            }
        }
      
      while ( i >= 0) {
         ans.push_back(abs(arr[i] * arr[i]));
          i--;
      }
      
      while ( j < len) {
         ans.push_back(arr[j] * arr[j]);
              j++;
      }
      
      return ans;
    }
};