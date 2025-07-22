//PROBLEM :

      Given the root of a binary tree, return its maximum depth.
      
      A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.




//CODE :
      class Solution {
      public:
          int res(TreeNode* root , int sum)
          {
              if(root==NULL)
              {
                  return sum;
              }
              if(root->left!=NULL || root->right!=NULL)
              {
                  sum+=1;
              }
              return max(res(root->left, sum ), res(root->right , sum));
          }
          int maxDepth(TreeNode* root) {
              if(root==NULL)
              {
                  return 0;
              }
             int val=res(root , 1);
             return val;
      
          }
      };
