class Solution {
public:
  
    int dp[301][301];
  
    int func(int index, string s, string tmp, int left_index, unordered_map<string, bool> &m) {
      if (index == s.size()) {
        //cout<<tmp<<endl;
        if (tmp.size() == 0)
          return 1;
        return 0;
      }
      
      if (dp[index][left_index] != -1)
        return dp[index][left_index];
      
     tmp += s[index];
     bool val = 0;
      
     if (m.find(tmp) != m.end()) {
       val += func(index+1, s, "", index+1, m);
     } 
      
      val += func(index+1, s, tmp, left_index, m);
      dp[index][left_index] = val;
      return val;
    }
  
    bool wordBreak(string s, vector<string>& wordDict) {
      unordered_map<string, bool> m;
      memset(dp, -1, sizeof(dp));
      
       for (int i = 0 ; i < wordDict.size() ; i++) {
         m[wordDict[i]] = true;
       }
      
      int val = func(0, s, "",0,  m);
      return val;
    }
};