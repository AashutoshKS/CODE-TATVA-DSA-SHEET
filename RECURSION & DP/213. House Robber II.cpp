//PROBLEM :

      You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in 
      a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically 
      contact the police if two adjacent houses were broken into on the same night.
      
      Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.


//APPROACH : 
      one : solve like gouse robber one for 2 cases 
          -> when you start from first house
          -> start from 2nd house. return their max
      two : Create a new list of repeated values
          ie. if nums = i, new array = nums[i] + nums[i]


        
//CODE :
      class Solution {
      public:
          int rob(vector<int>& nums) {
              int first=0;
              int second=0;
              if(nums.size()==1){
                  return nums[0];
              }
              vector<int>nums2(nums.begin(),nums.end());
              for(int i=0;i<nums.size();i++){
                  nums2.push_back(nums[i]);
              }
              for(int i=0;i<nums.size();i++){
                  nums[i]=max(second,first+nums[i]);
                  first=second;
                  second=nums[i];
              }
              first=0;
              second=0;
              for(int i=0;i<nums2.size();i++){
                  nums2[i]=max(second,first+nums2[i]);
                  first=second;
                  second=nums2[i];
              }
              return nums2.back()-nums.back();
          }
      };
