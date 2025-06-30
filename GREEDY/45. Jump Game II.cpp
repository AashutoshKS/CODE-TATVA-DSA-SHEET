//PROBLEM :

      You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].
      
      Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:
      
      0 <= j <= nums[i] and
      i + j < n
      Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].


//APPROACH :
      Greedily check all the position where we can go from nums[i] 
      and keep tract track of the minimum moves to reach at nums[i]


//CODE :
      class Solution {
      public:
          int jump(vector<int>& nums) {
              vector<int>ans(nums.size(),nums.size());
              ans[0] = 0;
              for(int i = 0 ;i < nums.size() - 1 ; i++) {
                  int j;
                  if((i + nums[i]) >= nums.size()) j = nums.size() - 1;
                  else j = i + nums[i];
                  while(j > i) {
                      ans[j] = min(ans[i] + 1, ans[j]);
                      if(j == nums.size() - 1) return ans[nums.size() - 1];
                      j--;
                  } 
                  
              }
              return ans[nums.size() - 1];
          }
      };
