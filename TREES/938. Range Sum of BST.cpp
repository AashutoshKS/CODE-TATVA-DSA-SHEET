//PROBLEM :

      Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

 

//APPROACH :
      for all node check if it us within the range or not


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(1)



//CODE :
      class Solution {
      public:
          int rangeSumBST(TreeNode* root, int low, int high) {
              if(root == nullptr)
                  return 0;
              if(root->val < low)
                  return rangeSumBST(root->right,low,high);
              if(root->val > high)
                  return rangeSumBST(root->left,low,high);
              return root->val + rangeSumBST(root->right,low,high) + rangeSumBST(root->left,low,high); 
          }
      };
