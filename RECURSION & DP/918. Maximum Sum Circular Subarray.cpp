//PROBLEM :

      Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
      
      A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous 
      element of nums[i] is nums[(i - 1 + n) % n].
      
      A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not 
      exist i <= k1, k2 <= j with k1 % n == k2 % n.



//APPROACH :
      Use Kadaend's algo to find maximum subarray sum and minimum subaaray sum
        since the array is circular ......
      the maximum sum will be either the maximum sum or overall_sum - min_sum (why?... do a dry run)
 


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(1)


        
//CODE :
      class Solution {
      public:
          int maxSubarraySumCircular(vector<int>& nums) {
              int sum = 0;
              for(int i : nums) sum += i;
              int ans1 = INT_MIN;
              int maxsum = 0;
              for(int i = 0;i < nums.size(); i++) {
                  maxsum += nums[i];
                  ans1 = max(ans1,maxsum);
                  if(maxsum < 0) maxsum = 0;
                  
              }
              int ans2 = INT_MAX;
              int minsum = 0;
              for(int i = 0;i < nums.size(); i++) {
                  minsum += nums[i];
                  ans2 = min(ans2,minsum);
                  if(minsum > 0) minsum = 0;
                  
              }
              if(sum == ans2) return ans1;
              return max(ans1, sum - ans2);
          }
      };
