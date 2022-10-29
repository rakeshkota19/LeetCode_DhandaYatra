class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int len = arr.size();
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
      
        int curr_sum = 0, left = 0, right = len - 1;
        for (int i = 0 ; i < len ; i++) {
          
            curr_sum = arr[i];
            left = i+1;
            right = len - 1;
          
            while(left < right) {   
               //cout<<left<<" "<<right<<endl;
            
                curr_sum = arr[i] + arr[left] + arr[right];

                if (curr_sum == 0 ) {
                    // cout<<i<<" "<<left<<" "<<right<<endl;
                    ans.push_back({arr[i], arr[left], arr[right]});
                }

                if (curr_sum > 0) {
                    right--;
                    
                  while (left < right && arr[right] == arr[right+1]) {
                        right--;
                  }
            
                } else {
                    left++;
                  
                    while (left < right && arr[left] == arr[left-1]) {
                      left++;
                  }
                }
                
                        // cout<<left<<" "<<right<<endl;


            }
          
          while ( i < len -1  && arr[i] == arr[i+1]) {
              i++;
            }  
        }

        return ans;
    }
};