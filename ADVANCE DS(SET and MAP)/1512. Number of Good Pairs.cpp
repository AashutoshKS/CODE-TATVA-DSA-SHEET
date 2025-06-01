//PROBLEM :
      Given an array of integers nums, return the number of good pairs.
      
      A pair (i, j) is called good if nums[i] == nums[j] and i < j.
      

//APPROACH :
      use map to count the frequency of number before index, count ans return the sum;


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)



//CODE :
      class Solution {
      public:
          int numIdenticalPairs(vector<int>& nums) {
              int ans = 0;
              map<int,int>mp;
              for (int i = 0; i < nums.size(); i++) {
                  ans += mp[nums[i]];
                  mp[nums[i]]++;
              }
              return ans;
          }
      };
