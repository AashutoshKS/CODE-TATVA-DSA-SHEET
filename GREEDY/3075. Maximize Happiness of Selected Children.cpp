//PROBLEM :

        You are given an array happiness of length n, and a positive integer k.
        
        There are n children standing in a queue, where the ith child has happiness value happiness[i]. You want to select k children from these n children in k turns.
        
        In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value 
        cannot become negative and gets decremented only if it is positive.
        
        Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.


//APPROACH :
        To maximise happiness pick the child with maximum happiness value, 
        sort the list in reverse order 
        at each index reduce the happiness by number of childrens selected till now


//COMPLEXITY :
        TIME COMPLEXITY : O(n.logn)
        SPACE COMPLEXITY : O(1)


//CODE :
      class Solution {
      public:
          long long maximumHappinessSum(vector<int>& nums, int k) {
              sort(nums.rbegin(),nums.rend());
              long long ans = 0;
              int sub = 0;
              for(int i = 0; i < nums.size(); i++,sub++) {
                  if(nums[i] <= sub) break;
                  if(k-- == 0) break;
                  nums[i] -= sub;
                  ans += nums[i];
              }
              return ans;
          }
      };
