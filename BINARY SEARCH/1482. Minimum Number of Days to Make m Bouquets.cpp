//PROBLEM :

      You are given an integer array bloomDay, an integer m and an integer k.
      
      You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
      
      The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
      
      Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.


//APPROACH : 
      if it is possible to make the flowers either we will make it in minimum days or maximum days
      the search space reduces to min - max of the given bloomsday array


//COMPLEXITY :
      TIME COMPLEXITY : O(n.logn)
      SPACE COMPLEXITY : O(1)


//CODE :
        class Solution {
        public:
            bool solve(vector<int>& nums, int m, int k,int mid ) {
                int count  = 0;
                int book = 0;
                for(int i = 0;i < nums.size();i++) {
                    if(nums[i] <= mid) count++;
                    else count = 0;
                    if(count == k) {
                        count = 0;
                        book++;
                    }
                }
                return book >= m;
            }
            int minDays(vector<int>& nums, int m, int k) {
                int low = *min_element(nums.begin(),nums.end());
                int high = *max_element(nums.begin(),nums.end());
                int ans = INT_MAX;
                while( low <= high) {
                    int mid = low + (high - low) /2 ;
                    if(solve(nums,m,k,mid) == true) {
                        ans = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                if(ans == INT_MAX) return -1;
                return ans;
            }
        };
