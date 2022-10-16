class Solution {
public:
    struct comp {
      bool operator()(int a, int b) {
        return a > b;  
      }
    };
  
    int findKthLargest(vector<int>& arr, int k) {
      priority_queue<int, vector<int>, comp> pq;
      
      int len = arr.size();
      
      for (int i = 0 ; i < k ; i++) {
        pq.push(arr[i]);
      }
      
      
      for (int i = k ; i < len ; i++) {
        if (pq.top() < arr[i]) {
          pq.pop();
          pq.push(arr[i]);
        }
      }
      
      return pq.top();
    }
};