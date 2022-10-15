class Solution {
public:
  
    // understand problem, return k smallest pairs
    // constrainsts - 10pow5
    // edge cases - no
    // brute force - Check for all elements, store sum in array, sort and return them - n^2 logn
    // optimsation - check for all elements, have a max heap of k elemts, complexity - n^2
    // more optimisation, do a dijskra like approach

    typedef pair<int, int> pp;
    typedef pair<int, pp> ppp;
  
   struct func {
     bool operator()(ppp a, ppp b) {
       return a.first > b.first;
     }
   };
  
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
      
      pair<int, int> p;
      priority_queue<ppp, vector<ppp>, func> pq;
      vector<vector<int>> ans;
      
      int len1 = nums1.size(), len2 = nums2.size();
      
      if (len1 == 0 || len2 == 0)
        return ans;
      
      pq.push( { nums1[0] + nums2[0], {0, 0}});
      set<pp> s;
      
      
      while (k-- && !pq.empty()) {
        ppp val = pq.top();
        pq.pop();
                
        int i = val.second.first, j = val.second.second;
        //cout<<val.first<<" "<<i<<" "<<j<<endl;
        
          
        if (s.find(val.second) != s.end()) {
          k++;
          continue;
        }
        
        s.insert(val.second);
        ans.push_back({nums1[i], nums2[j]});
        
                
        if (i + 1 < len1 && s.find({i+1,j}) == s.end())
          pq.push( { nums1[i+1] + nums2[j], {i+1, j} } );
                  
         if (j + 1 < len2 && s.find({i, j+1}) == s.end())
          pq.push( { nums1[i] + nums2[j+1], {i, j+1} } );

      }
      
      return ans;
    }
};