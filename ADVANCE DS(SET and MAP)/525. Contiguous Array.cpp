//PROBLEM :

      Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.



//APPROACH :
          calculate the sum as follows. if you find a 1 add 1 to the sum; if you find 0 substract 1 from the sum.
                nums = [1,1,0,0,1,1,0,1,1]
                sum = [1,2,1,0,1,2,1,2,3]
          Observe it carefully. If you find a sum which you have already found. you actually have a subarr with equal number of 0's and 1's.


//COMPLEXITY : 
        TIME COMPLEXITY : O(n)
        SPACE COMPLEXITY : O(n)


//CODE :
      class Solution {
      public:
          int findMaxLength(vector<int>& nums) {
              nums.insert(nums.begin(), 0);
              map<int,int>mp;
              for(int i = 1; i < nums.size(); i++) {
                  if(nums[i] == 1) nums[i] = nums[i-1] + 1;
                  else nums[i] = nums[i-1] - 1;
              }
              int ans = 0;
              for(int i = 0; i < nums.size(); i++) {
                  if(mp[nums[i]] == 0) mp[nums[i]] = i + 1;
                  int val = i - mp[nums[i]] + 1;
                  ans = max(ans,val);
              }
              return ans;
          }
      };
