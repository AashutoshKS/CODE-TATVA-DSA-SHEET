//PROBLEM :
      Given head, the head of a linked list, determine if the linked list has a cycle in it.
      
      There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
        Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
      
      Return true if there is a cycle in the linked list. Otherwise, return false.



//APPROACH :
      Use slow and fast pointer approach
      slow moves one pointer at a time and fast moves 2 pointer
        if there is no cycle fast pointer will reach the null
        else both the pointers will meet at a point



//CODE :

      class Solution {
       public:
        bool hasCycle(ListNode* head) {
          ListNode* slow = head;
          ListNode* fast = head;
      
          while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
              return true;
          }
          return false;
        }
      };
