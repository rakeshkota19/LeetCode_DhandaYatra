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

// 1
// 2 3
// 4 5 6 7
  
  typedef unsigned long long int ll;

  unordered_map<int, ll>m;
  int ans = 1;


  void inorder(TreeNode *ptr, ll count, int height) {
    if (ptr == NULL)
      return;
    
    cout<<ptr->val<<" "<<count<<endl;
    
    if (m.find(height) == m.end())
      m[height] = count;
    else {
      //cout<<count<<" "<<m[height]<<endl;
      ll val = count - m[height] + 1;
      
     if (val > ans)
      ans = val;
    }
    
    if (ptr->left != NULL)
      inorder(ptr->left, count*2 + 1, height + 1);
    
    if (ptr->right != NULL)
      inorder(ptr->right, count*2 + 2, height + 1);
}  
  

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        m.clear();
        ans = 1;
        inorder(root, 0, 0);
         return ans;
    }
};