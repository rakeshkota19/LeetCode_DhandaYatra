class Solution {
public:
  
   // Binary search + Exponenetatipn
  
    typedef long long int ll;
    ll di = pow(10, 9) + 7;
    ll ans;
  
    int power(ll val) {
      ll ret = 1;
  
      if (val == 0)
        return 1;
 

    if (val % 2 == 0) {
        ret = power(val/ 2);
        ret = (ret * ret) % di;
    }

    else {
        ret = 2;
        ret = (ret * power(val - 1) % di) % di;
    }
 
    return (ret + di) % di;
   }
 
  
    int numSubseq(vector<int>& nums, int target) {
        int len = nums.size();
        ans = 0;
      
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < len ; i++) {
          int right_val = target - nums[i];
          
          
          if (nums[i] >= target)
            break;
          
          
          int right_index = (upper_bound(nums.begin(), nums.end(), right_val)) - nums.begin() - 1;
          
          if (right_index < i)
            continue;
          
          
          ans += power(right_index-i);
          ans %= di;
        }
      
      return ans;
    }
  
};