//PROBLEM :
        Given an array of integers nums, you start with an initial positive value startValue.
        
        In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).
        
        Return the minimum positive value of startValue such that the step by step sum is never less than 1.


//APPROACH : 
        min value of startval such that the overall sum is never < 1 is equal to 1 - minimum....
        since it will never let the sum go below 1

          
//COMPLEXITY :
        TIME COMPLEXITY : O(n)
        SPACDE COMPLEXITY : O(1)


//CODE :
        class Solution {
        public:
            int minStartValue(vector<int>& nums) {
                int min1 = 0, sum = 0;
                for (int i = 0; i < nums.size(); i++) {
                    sum += nums[i];
                    min1 = min(min1, sum);
                }
                return 1 - min1;
            }
        };
