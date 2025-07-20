//PROBLEM :

      Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false 
      otherwise.
      
      A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a 
      subtree of itself.


        
//CODE :
      class Solution {
      public:
          int ans = 0;
          bool isSameTree(TreeNode* p, TreeNode* q) {
              if ( p == nullptr || q == nullptr) {
                  return p == q;
              }
              return p -> val == q -> val &&
                      isSameTree(p -> left ,q -> left) &&
                      isSameTree(p -> right ,q -> right);
          }
      
          void solve(TreeNode* root, TreeNode* subRoot) {
              if(root == nullptr || ans == 1) return;
              if(root -> val == subRoot -> val){
                  if(isSameTree(root, subRoot)) {
                      ans = 1;
                  }
              } 
              solve(root -> right, subRoot);
              solve(root -> left, subRoot);
          }
          bool isSubtree(TreeNode* root, TreeNode* subRoot) {
              solve(root, subRoot);
              return ans == 1;
          }
      };
