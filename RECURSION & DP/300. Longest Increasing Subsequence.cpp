//PROBLEM : 

      Given an integer array nums, return the length of the longest strictly increasing subsequence.



//CODE :
      class Solution {
        public:
            int lengthOfLIS(vector<int>& nums) {
                vector<int> num(nums.size(), 1);
                int n = nums.size();
                if(n == 1) return 1;
                for(int i = 1; i < n; i++) {
                    for(int j = 0; j < i; j++) {
                        if(nums[i] > nums[j]) {
                            num[i] = max(num[i], num[j] + 1);
                        }
                    }
                }
                return *max_element(num.begin(), num.end());
            }
        };
