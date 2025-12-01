//PROBLE :

      Given the head of a singly linked list, return true if it is a palindrome or false otherwise.



//APPROACH :
        You can simple solve it using a list if its not an interview....
        Its is simple and quick and less error prone...

//CODE :

      class Solution {
      public:
          bool isPalindrome(ListNode* head) {
              vector<int>ch;
              while(head != nullptr){
                  ch.push_back(head -> val);
                  head = head -> next;
              }
              int i=0,j=ch.size()-1;
              while( i < j){
                  if(ch[i] != ch[j]){
                      return false;
                  }
                  i++;
                  j--;
              }
              return true;
          }
      };


//APPROACH :
else find the mid point and reverse one side of the linked list 
then check if it is palindrome



//CODE :

      class Solution {
       public:
        bool isPalindrome(ListNode* head) {
          ListNode* slow = head;
          ListNode* fast = head;
      
          while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
          }
      
          if (fast != nullptr)
            slow = slow->next;
          slow = reverseList(slow);
      
          while (slow != nullptr) {
            if (slow->val != head->val)
              return false;
            slow = slow->next;
            head = head->next;
          }
      
          return true;
        }
      
       private:
        ListNode* reverseList(ListNode* head) {
          ListNode* prev = nullptr;
          while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
          }
          return prev;
        }
      };
