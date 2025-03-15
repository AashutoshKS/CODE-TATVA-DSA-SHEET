//PROBLEM :
        You are given an integer array nums sorted in non-decreasing order.
        
        Build and return an integer array result with the same length as nums such that result[i] is equal to the summation of absolute differences between 
        nums[i] and all the other elements in the array.
        
        In other words, result[i] is equal to sum(|nums[i]-nums[j]|) where 0 <= j < nums.length and j != i (0-indexed).

//COMPLEXITY : 
        TIME COMPLEXITY : O(n)
        SPACE COMPLEXITY : O(n)


//CODE :
        class Solution {
        public:
            vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
                vector<int>ans(nums.size());
                int n = nums.size();
                for(int i = 1; i < nums.size();i++) {
                    nums[i] += nums[i-1];
                }
                for(int i = 0; i < nums.size();i++) {
                    if(i == 0) {
                        ans[i] = nums.back() - nums[0] - (n-1)*nums[0];
                        continue;
                    }
                    int r = n - i - 1;
                    int l = n - r - 1;
                    long long add_r = nums.back() - nums[i] - r*(nums[i] - nums[i-1]);
                    long long add_l = l*(nums[i] - nums[i-1]) - nums[i-1];
                    ans[i] = add_r + add_l;
                }
                return ans;
            }
        };
