//PROBLEM :
      You are given the root of a binary search tree (BST) and an integer val.
      
      Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.


//APPROACH :
      BST holds a property 
        all the right node of a rool are larger than root, 
        left nodes are smaller than root
      traverse based on the target element and root value



//CODE 1 :
      class Solution {
      public:
          TreeNode* searchBST(TreeNode* root, int val) {
              if(root == nullptr)
                return nullptr;
              if(root->val==val)
                return root;
              if(root->val > val)
                return searchBST(root->left,val);
              return searchBST(root->right,val);
          }
      };
