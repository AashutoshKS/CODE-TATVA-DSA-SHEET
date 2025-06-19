//PROBLEM :

      Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
      
      In one move, you can increment n - 1 elements of the array by 1.


//APPROACH : 
      return sum of difference between nums[i] - minimun(nums)
      why?


//COMPLEXITY :
      TIME COMPLEXIITY : O(n)
      SPACE COMPLEXITY : O(1)


        
//CODE :

Java Script 
        
      var minMoves = function(nums) {
          let mini = Math.min(...nums);
          let ans = 0;
          for(let i = 0;i < nums.length; i++) {
              ans += parseInt(nums[i] - mini)
          }
          return ans;
      };


C++
      class Solution {
      public:
          int minMoves(vector<int>& nums) {
              int count=0;
              int min=*min_element(nums.begin(),nums.end());
              for(int i=0;i<nums.size();i++){
                  count+=nums[i]-min;
              }
              return count;
          }
      };
       
      
