//PROBLEM :

      Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
      
      Implement the MinStack class:
      
      MinStack() initializes the stack object.
      void push(int val) pushes the element val onto the stack.
      void pop() removes the element on the top of the stack.
      int top() gets the top element of the stack.
      int getMin() retrieves the minimum element in the stack.
      You must implement a solution with O(1) time complexity for each function.



//CODE :
      class MinStack {
      public:
      stack<pair<int,int>>ans;
          MinStack() {
          
          }
          
          void push(int val) {
              if(ans.empty()) ans.push({val,val});
              else {
                  int x = min(val,ans.top().second);
                  ans.push({val,x});
              }
          }
          
          void pop() {
              ans.pop();
          }
          
          int top() {
              return ans.top().first;
          }
          
          int getMin() {
              return ans.top().second;
          }
      };
