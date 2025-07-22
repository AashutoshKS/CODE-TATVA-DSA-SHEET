//PROBLEM :

      Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


//CODE :
    class Solution {
    public:
        bool solve(TreeNode* Left, TreeNode* Right) {
            if(Right == nullptr && Left == nullptr) return true;
            if(Right == nullptr || Left == nullptr || Right -> val != Left -> val) return false;
            // for symmetry, if you move to left in left tree move right in the right tree and vise versa
            return solve(Left -> left, Right -> right) && solve(Left -> right, Right -> left);
        }
        bool isSymmetric(TreeNode* root) {
            return solve(root, root);
        }
    };
