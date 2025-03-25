//PROBLEM :
              Given an integer array nums, find three numbers whose product is maximum and return the maximum product.



//APPROACH :
              For product of 3 numbers ro be maximum assuming +ve result, product of 3 numbers are positive if
                -> 2 -ve, 1 +ve
                -> 3 +ve
              
              for product to be maximum in both the cases
                -> for 2 -ve number both must be the least number and the +ve number should be maximum
                -> for all +ve all the number must be the highest

              Which is possible after sorting the vector


//COMPLEXITY : 
            TIME COMPLEXITY : O(n.logn)
            SPACE COMPLEXITY : O(1)


//CODE :
            class Solution {
            public:
                int maximumProduct(vector<int>& nums) {
                    sort(nums.begin(), nums.end());
                    int n = nums.size();
                    return max(nums[n - 1] * nums[0] * nums[1],
                               nums[n - 1] * nums[n - 2] * nums[n - 3]);
                }
            };
