//PROBLEM
      
      Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.
      
      Return the positive integer k. If there is no such integer, return -1.



//APPROACH :
        store the values in map and check linearly


      
//COMPLEXITY :
        TIME COMPLEXITY : O(n)
        SPACE COMPLEXITY : O(n)



//CODE :
        class Solution {
        public:
            int findMaxK(vector<int>& nums) {
                unordered_map<int,int>mp;
                int ans = -1;
                for(int i = 0;i < nums.size(); i++) {
                    mp[nums[i]]++;
                    if(mp[-nums[i]] != 0) ans = max(ans,abs(nums[i]));
                }
                return ans;
            }
        };
