//PROBLEM :
            Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.


//APPROACH :
              i) either find squares of each idx and sort it
              ii) or sort the abs vector and then square it

//CODE :
              class Solution {
              public:
                  vector<int> sortedSquares(vector<int>& nums) {
                      for(int i=0;i<nums.size();i++){
                          nums[i]=nums[i]*nums[i];
                      }
                      sort(nums.begin(),nums.end());
                      return nums;
                  }
              };
