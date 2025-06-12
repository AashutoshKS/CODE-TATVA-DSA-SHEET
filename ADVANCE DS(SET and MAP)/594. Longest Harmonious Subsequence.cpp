//PROBLEM :

      We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
      
      Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.



//APPROACH :
      Count frequency of each element 
      for maximum answer 
      we require 2 elements such that abs(num1 - num2) = 1
        thus compute all possible pairs of numbers ans return the maximum sum of them


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)



//CODE :
      class Solution {
      public:
          int findLHS(vector<int>& nums) {
              map<int,int>mp;
              for(int i : nums) mp[i]++;
              int ans = 0;
              for(int i = 0;i < nums.size(); i++) {
                  if(mp[nums[i] - 1] != 0) {
                      ans = max(ans, mp[nums[i]] + mp[nums[i] - 1]);
                  }
                  if(mp[nums[i] + 1] != 0) {
                      ans = max(ans, mp[nums[i]] + mp[nums[i] + 1]);
                  }
              } 
              return ans;
          }
      };
