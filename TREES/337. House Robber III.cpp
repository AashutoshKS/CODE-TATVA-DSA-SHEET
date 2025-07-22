//PROBLEM :

      The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.
      
      Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. 
        It will automatically contact the police if two directly-linked houses were broken into on the same night.
      
      Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.


//CODE :
      class Solution {
      public:
          int rob(TreeNode* root) {
              auto res = dfs(root);
              return max(res.first, res.second);
          }
          
      private:
          pair<int,int> dfs(TreeNode* node) {
              if (node == nullptr) return {0, 0};
              
              auto L = dfs(node->left);
              auto R = dfs(node->right);
              
              int rob    = node->val + L.second + R.second;
              int no_rob = max(L.first, L.second) + max(R.first, R.second);
              
              return {rob, no_rob };
          }
      };
