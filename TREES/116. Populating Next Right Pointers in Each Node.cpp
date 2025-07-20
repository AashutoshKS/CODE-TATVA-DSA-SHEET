//PROBLEM :

      You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
      
      struct Node {
        int val;
        Node *left;
        Node *right;
        Node *next;
      }
      Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
      
      Initially, all next pointers are set to NULL.



//CODE :
      class Solution {
      public:
          Node* connect(Node* root) {
              if(root == nullptr) return root;
              queue<Node*>q;
              q.push(root);
              while(!q.empty()) {
                  int n = q.size();
                  while(n--) {
                      Node* curr = q.front();
                      q.pop();
                      if(n == 0) curr -> next = nullptr;
                      else curr -> next = q.front();
                      if(curr -> left != nullptr) q.push(curr -> left);
                      if(curr -> right != nullptr) q.push(curr -> right);    
                  }
              }
              return root;
      
          }
      };
