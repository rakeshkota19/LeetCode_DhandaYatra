class Solution {
public:
  
  char checkandReturnAlphabet(char c) {
    if (( c >= 'a'  && c <= 'z') | (c >= 'A' && c <= 'Z')) {
      return true;
    } 
    
    return false;
  }
  
  char returnAlternateChar(char c) {
     if ( c >= 'a'  && c <= 'z')
       return c - 32;
    
    if (c >= 'A' && c <= 'Z')
      return c + 32;
    
    return 'a';
  }
  
  
    void func(int index, string s, string tmp, vector<string> &ans) {
      if (index == s.size()) {
        ans.push_back(tmp);
        return;
      }
      
      func(index+1, s, tmp + s[index], ans);
      if (checkandReturnAlphabet(s[index]))
        func(index+1, s, tmp + returnAlternateChar(s[index]), ans);

    }
  
    vector<string> letterCasePermutation(string s) {
        int size = s.size();
      
        vector<string> ans;
        func(0, s, "", ans);
      return ans;
    }
};