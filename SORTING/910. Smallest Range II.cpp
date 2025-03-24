//PROBLEM :
              You are given an integer array nums and an integer k.
              
              For each index i where 0 <= i < nums.length, change nums[i] to be either nums[i] + k or nums[i] - k.
              
              The score of nums is the difference between the maximum and minimum elements in nums.
              
              Return the minimum score of nums after changing the values at each index.


//APPROACH :
              Sort the array 
              if n lies between 0 < size 
                      then we have to increment all the values in range 0-n
                      and decrement the values in range n + 1 - size
              
              So greedily we will check for all the index that which index is suitable  to get the minimum answer


//COMPLEXITY : 
              TIME COMPLEXITY : O(n.logn)
              SPACE COMPLEXITY : O(1)


//CODE :
              class Solution {
              public:
                  int smallestRangeII(vector<int>& nums, int k) {
                      sort(nums.begin(),nums.end());
                      if(k == 0) return nums.back() - nums[0];
                      int ans = nums.back() - nums[0];
                      for(int i = 0;i < nums.size() - 1; i++) {
                          int j = i+1;
                          int small = min(nums[0] + k, nums[j] - k);
                          int big = max(nums[i] + k, nums.back() - k);
                          ans = min(ans,big - small);
                      }
                      return ans;
                  }
              };
