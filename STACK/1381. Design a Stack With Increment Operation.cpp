//PROBLEM :

      Design a stack that supports increment operations on its elements.
      
      Implement the CustomStack class:
      
      CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
      void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
      int pop() Pops and returns the top of the stack or -1 if the stack is empty.
      void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements 
      in the stack.




//APPROACH :
      Simple push, pop beware of the index out of bound error



//CODE :
      class CustomStack {
      public:
          vector<int>nums;
          int n;
          CustomStack(int maxSize) {
              n = maxSize;
          }
          
          void push(int x) {
              if(nums.size() == n) ;
              else nums.push_back(x);
          }
          
          int pop() {
              if(nums.size() == 0) return -1;
              int val = nums.back();
              nums.pop_back();
              return val;
          }
          
          void increment(int k, int val) {
              for(int i = 0;i < nums.size() && i < k; i++) nums[i] +=  val;
          }
      };
