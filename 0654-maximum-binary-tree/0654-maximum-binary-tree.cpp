/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  
    typedef TreeNode* node;
  
   int max_index(int low, int high, vector<int> &nums) {
     int max_val = nums[low];
     int ind = low;
 
     //cout<<low<<" "<<high<<endl;
     
     for(int i = low + 1; i <= high ; i++) {
        if (max_val < nums[i]) {
          ind= i;
          max_val = nums[i];
        }
     }
     
     return ind;
   }
  
   node build(int low, int high, vector<int> &nums) {
    int index = max_index(low, high, nums);
     //cout<<index<<" "<<nums[index]<<endl;
     
     if (low > high)
       return NULL;

     node nn = new TreeNode(nums[index]);
     
     nn->left = build(low, index - 1, nums);
     nn->right = build(index+1, high, nums);
     return nn;
     
   }
  
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
     // sort(nums.begin(), nums.end());
      int len = nums.size() - 1;
      
      return build(0,len, nums);
    }
};