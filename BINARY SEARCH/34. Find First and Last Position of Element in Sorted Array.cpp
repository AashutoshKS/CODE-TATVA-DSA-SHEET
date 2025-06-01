//PROBLEM :

        Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
        
        If target is not found in the array, return [-1, -1].
        
        You must write an algorithm with O(log n) runtime complexity.


//APPROACH 1: 
          Can be find using linear search in complexity O(n)


//APPROACH 2: 
          use upper bound and lower bound algorithm if the indexed cross each other that means the element are not present and return {-1.-1}
          else return {lower bound,upper bound}

          
//COMPLEXITY :
          TIME COMPLEXITY : O(n)
          SPACE COMPLEXITY : O(1)

//CODE 1:
          class Solution {
          public:
              vector<int> searchRange(vector<int>& nums, int target) {
                  int first,second;
                  if(nums.size()==0){
                      return {-1,-1};
                  }
                  for(int i=0;i<nums.size();i++){
                      if(nums[i]==target){
                          first=i;
                          break;
                      }
                      if(i==nums.size()-1 && nums[i]!= target){
                          return {-1,-1};
                      }
                  }
                  for(int i=nums.size()-1;i>=first;i--){
                      if(nums[i]==target){
                          second=i;
                          break;
                      }
                  }
                  return {first,second};
              }
          };



-------------------------------------------------------------------------------------------------------------------------------------------------------
          
//COMPLEXITY :
          TIME COMPLEXITY : O(logn)
          SPACE COMPLEXITY : O(1)
  

//CODE :
      class Solution {
       public:
        vector<int> searchRange(vector<int>& nums, int target) {
          const int l = ranges::lower_bound(nums, target) - nums.begin();
          if (l == nums.size() || nums[l] != target)
            return {-1, -1};
          const int r = ranges::upper_bound(nums, target) - nums.begin() - 1;
          return {l, r};
        }
      };
