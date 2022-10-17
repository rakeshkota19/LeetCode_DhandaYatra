class Solution {
public:
  
   int dp[5001][1001][2];
   int func(vector<int> &prices, int index, int buy_val, int flag) {
     if (index >= prices.size()) {
       return 0;
     }
          
     if (dp[index][buy_val][flag] != -1) {
       return dp[index][buy_val][flag];
     }
     
     int ans = 0;
     
     if (flag) {
       ans = max(ans, prices[index] - buy_val + func(prices, index+2, 0, 0));
       ans = max(ans, func(prices, index+1, buy_val, 1));
     } else {
       ans = max(ans, func(prices, index+1, prices[index], 1));
       ans = max(ans, func(prices, index+1, 0, 0));
     }
     
     
      dp[index][buy_val][flag] = ans;
     return ans;
   }
  
    int maxProfit(vector<int>& prices) {
      memset(dp, -1, sizeof(dp));
      int ans = func(prices, 0, 0, 0);
      return ans;
    }
};