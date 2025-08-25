//PROBLEM :

      Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack 
      (push, top, pop, and empty).
      
      Implement the MyStack class:
      
      void push(int x) Pushes element x to the top of the stack.
      int pop() Removes the element on the top of the stack and returns it.
      int top() Returns the element on the top of the stack.
      boolean empty() Returns true if the stack is empty, false otherwise.
      Notes:
      
      You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
      Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as 
        you use only a queue's standard operations.


//APPROACH :
      you have to use 2 queue
      which pushing any element first push all the element of queue 1 in queue 2
      so that the current element can be pushed as the 1st elemnt of the queue for pop in O(1)
        push -> O2*n)
        push -> O(1)
        empty -> O1)
        top -> O(1)
        

//CODE :
      class MyStack {
      public:
          queue<int> q1;
          queue<int> q2; 
          MyStack() {
              
          }
          
          void push(int x) { //O(n)
              while(!q1.empty()){
                  q2.push(q1.front());
                  q1.pop();
              }
              q1.push(x);
      
              while(!q2.empty()){
                  q1.push(q2.front());
                  q2.pop();
              }
          }
          
          int pop() { //O(1)
              int ans = q1.front();
              q1.pop();
              return ans;
          }
          
          int top() { //O(1)
              return q1.front();
          }
          
          bool empty() { //O(1)
              return q1.empty();
          }
      };
