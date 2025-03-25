//PROBLEM 

            The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs.
            
            For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
            Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:
            
            Each element of nums is in exactly one pair, and
            The maximum pair sum is minimized.
            Return the minimized maximum pair sum after optimally pairing up the elements.


//APPROACH : 
              to have sum as minimum we have to pair the maximum element with the least element
              sort ans use 2 pointer


//CODE :
            class Solution {
            public:
                int minPairSum(vector<int>& nums) {
                    sort(nums.begin(), nums.end());
                    int max_sum = INT_MIN, sum;
                    for (int i = 0, j = nums.size() - 1; i < j; i++, j--) {
                        sum = nums[i] + nums[j];
                        max_sum = max(max_sum, sum);
                    }
                    return max_sum;
                }
            };
