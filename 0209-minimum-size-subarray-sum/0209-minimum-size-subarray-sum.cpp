class Solution {
public:
    // understand question  - find the subarray - having sum > target, return the smallest subarray size
   // consttraints - 10pow5 
    // edge cases, no such sub array - return
   // all elements are positive 
   // B.F - find all subarrays and return answer O(n2)
  // Try to do sliding window, moving left and right pointer 
  
  typedef long long int ll;
  
    int minSubArrayLen(int target, vector<int>& arr) {
      
      int ans = 0, len = arr.size(), i, left, right;
      ll curr_sum = 0;
      
      for ( i = 0 ; i < len ; i++) {
        curr_sum += arr[i];

          if (curr_sum >= target)
            break;

      }

      if ( i == len)
        return 0;

    ans = i+1;
    right = i+1;
    left = 0;
    

    for ( int j = ans; j < len ; j++) {

        if (curr_sum >= target) {
            ans = min(ans, j - left + 1);
        }

        curr_sum += arr[j];

        while(curr_sum - arr[left] >= target && left < j) {
            curr_sum -= arr[left];
            left++;
            ans = min(ans, j - left + 1);
        }
    }
      
    // handle case where whole sum is greater than target, and we can trim some left characters
    while(curr_sum - arr[left] >= target && left < len) {
            curr_sum -= arr[left];
            left++;
            ans = min(ans, len - left );
        }

    return ans;
        
    }
};