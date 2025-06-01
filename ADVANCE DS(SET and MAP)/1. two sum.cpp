//PROBLEM :
      Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
      
      You may assume that each input would have exactly one solution, and you may not use the same element twice.
      
      You can return the answer in any order.


//APPROACH 1 : 
    check all possibilities 
    complexity O(n*n)


//APPROACH 2 :
    use map to find frequency and if the 2nd elemnt is present or not

//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)


//CODE :
      class Solution {
      public:
          vector<int> twoSum(vector<int>& nums, int target) {
              unordered_map<int,int>mp;
              for(int i=0;i<nums.size();i++){
                  int x = target - nums[i];
                  if(mp[x] != 0 && mp[x] != i+1){
                      return {mp[x]-1,i};
                  }
                  mp[nums[i]] = i + 1;
              }
              return {0};
          } 
      };
