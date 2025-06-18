//PROBLEM :
      Given an integer array nums and an integer k, return the kth largest element in the array.
      
      Note that it is the kth largest element in the sorted order, not the kth distinct element.
      
      Can you solve it without sorting?


//APPROACH : With sorting
      Sort and return the kth element

//COMPLEXITY :
      TIME COMPLEXITY : O(n.logn)
      SPACE COMPLEXITY : O(1)



//APPROACH 2 : Without sorting
        Use min heap of size k 
        pop the top whenever the height > k


//COMPLEXITY :
      TIME COMPLEXITY : O(n.logn)
      SPACE COMPLEXITY : O(k)


//CODE :
      class Solution {
      public:
          int findKthLargest(vector<int>& nums, int k) {
              priority_queue<int, vector<int>, greater<>> heap;
              for (int i=0;i<nums.size();i++) {
                  if(heap.size() == k && nums[i] <= heap.top())
                      continue; 
                  heap.push(nums[i]);
                  if (heap.size() > k)
                      heap.pop();
              }
              return heap.top();
          }
      };
