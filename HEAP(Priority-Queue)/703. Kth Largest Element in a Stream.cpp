//PROBLEM :

      You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. 
        This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.
      
      You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the 
        kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.
      
      Implement the KthLargest class:
      
      KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
      int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.



//APPROACH :
      Use min heap with size K, the top element will always represent the kth element


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(k)


//CODE :
      class KthLargest {
      public:
          priority_queue<int,vector<int>,greater<int>>pq;
          int v;
          KthLargest(int k, vector<int>& nums) {
              v = k;
              for(int i : nums) {
                  pq.push(i);
                  if(pq.size() > k) pq.pop();
              }
          }
          
          int add(int val) {
              pq.push(val);
              if(pq.size() > v) pq.pop();
              return pq.top();
          }
      };
