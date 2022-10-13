class Solution {
public:
    int lastRemaining(int n) {
      int start = 1;
      
      int current_iteration = 1;
      int diff = 1;
      bool flag = 0;
      
      while (n > 1) {
           // cout<<n<<" "<<"current iter: "<<current_iteration<<"start : "<<start<<endl;
           //  cout<<flag<<endl;

        n = (current_iteration & 1 || flag) ? n / 2 : ceil(n/2.0);
        
        if (current_iteration & 1 || flag) {
          start += diff;
          flag = 0;
        }
        
        diff = 2 * diff;
        
     
       
       current_iteration = (current_iteration + 1)%2;
        
      if (n&1 && current_iteration == 0) 
        flag = true;

      }
        
      return start;
    }
};