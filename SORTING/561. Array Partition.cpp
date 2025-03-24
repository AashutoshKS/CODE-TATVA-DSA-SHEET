//PROBLEM :
              Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn)
              such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.


//APPROACH :
            since we have to maximize the solution 
            and have to add minimum in the solution
            we have to take care to not pair greater element with small element....since in such a case the grater element cant be utilised
            this we sort the vector and consider each alternate element as pair
            so that we can utilise greater elements

//CODE :
              class Solution {
              public:
                  int arrayPairSum(vector<int>& nums) {
                      sort(nums.begin(),nums.end());
                      int ans=0;
                      for(int i=0;i<nums.size();i+=2){
                          ans=ans+nums[i];
                      }
                      return ans;
                  }
              };
