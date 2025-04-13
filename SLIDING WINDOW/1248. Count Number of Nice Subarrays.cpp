//PROBLEM :

              Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
              
              Return the number of nice sub-arrays.


//APPROACH :
              to check number of subarray with k odd elements we do not actually requre even number
              
              change the question to subarray sum equal k by
                 -> if number is even change it to 0 
                 -> if number is odd change it to 1
              
              
              Now use prefix sum to compute the number of subarray with sum equals k


//COMPLEXITY : 
              TIME COMPLEXITY : O(3*n) = O(n)
              SPACE COMPLEXITY : O(n)



//CODE :
            class Solution {
            public:
                int numberOfSubarrays(vector<int>& nums, int k) {
                    for(int i = 0; i <nums.size(); i++) {
                        if(nums[i]%2 == 0) nums[i] = 0;
                        else nums[i] = 1;
                    }
                    int count = 0;
                    unordered_map<int, int> mp;
                    mp[nums[0]]++;
                    for (int i = 1; i < nums.size(); i++) {
                        nums[i] = nums[i] + nums[i - 1];
                        mp[nums[i]]++;
                    }
                    for (int i = nums.size() - 1; i >= 0; i--) {
                        mp[nums[i]]--;
                        int x = nums[i] - k;
                        if (x == 0)
                            count++;
                        count += mp[x];
                    }
                    return count;
                }
            };
