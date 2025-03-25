//PROBLEM :
                Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.



//APPROACH :
                since values are repeating we can sort the vector and check the third unique number


//CODE :
                class Solution {
                public:
                    int thirdMax(vector<int>& nums) {
                        sort(nums.begin(), nums.end());
                        int ans = nums.back();
                        int count = 1;
                        for(int i = nums.size() - 2; i >= 0; i--) {
                            if(nums[i] != nums[i+1]) {
                                count++;
                            }
                            if(count == 3) return nums[i];
                        }
                        return ans;
                    }
                };
