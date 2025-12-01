//PROBLEM :

      Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.



//CODE :

      class Solution {
      public:
          ListNode* removeElements(ListNode* head, int val) {
              while (head && head->val == val) {
                  head = head->next;
              }
              if (!head) return nullptr;
      
              ListNode* curr = head;
      
              while (curr->next) {
                  if (curr->next->val == val) {
                      curr->next = curr->next->next;
                  } else {
                      curr = curr->next;
                  }
              }
      
              return head;
          }
      };
