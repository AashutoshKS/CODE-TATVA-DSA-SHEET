//PROBLEM :

      You are given an array nums of n positive integers.
      
      You can perform two types of operations on any element of the array any number of times:
      
      If the element is even, divide it by 2.
      For example, if the array is [1,2,3,4], then you can do this operation on the last element, and the array will be [1,2,3,2].
      If the element is odd, multiply it by 2.
      For example, if the array is [1,2,3,4], then you can do this operation on the first element, and the array will be [2,2,3,4].
      The deviation of the array is the maximum difference between any two elements in the array.
      
      Return the minimum deviation the array can have after performing some number of operations.




//APPROACH :
      make all elements even and push in the max heap.....
      also compute the minimum element in the heap
      perform the /2 operation in top of heap if they are even .....since it will reduce the deviation
      in each case push the new element and find the new minimum deviation.....
      return if top of heap is odd.....(since it is odd it can only be multiplied which will increase the deviation)



// CODE :
      class Solution {
      public:
          int minimumDeviation(vector<int>& nums) {
              priority_queue<int> pq;
              int mini = INT_MAX;
              for (int num : nums) {
                  if (num % 2 == 1)
                      num *= 2;
                  pq.push(num);
                  mini = min(mini, num);
              }
              int ans = INT_MAX;
              while (true) {
                  int val = pq.top();
                  pq.pop();
                  ans = min(ans, val - mini);
                  if (val % 2 == 1)
                      break;
                  val = val / 2;
                  mini = min(mini, val);
                  pq.push(val);
              }
              return ans;
          }
      };
