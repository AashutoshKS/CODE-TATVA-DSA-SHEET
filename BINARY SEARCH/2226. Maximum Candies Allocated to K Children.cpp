//PROBLEM :
        
        You are given a 0-indexed integer array candies. Each element in the array denotes a pile of candies of size candies[i]. 
        You can divide each pile into any number of sub piles, but you cannot merge two piles together.
        
        You are also given an integer k. You should allocate piles of candies to k children such that each child gets the same number of candies. 
          Each child can be allocated candies from only one pile of candies and some piles of candies may go unused.
        
        Return the maximum number of candies each child can get.
        
//APPROACH :
        if there is only 1 student you can give any candie to him, SINCE WE CANT MERGE 2 PILE, thus we will give the maximum one to him
        
        similarly if the sum of candies are < number of student you can not give candie to any one
        
        use binary search from range 0 - maximum,  and check if you can distribute the specific amount of candies or not 


//COMPLEXITY :
        TIME COMPLEXITY : O(n.logn)
        SPACE COMPLEXITY : O(1) 


//CODE :

        class Solution {
        public:
            bool solve(vector<int>& nums, long long k,int mid) {
                long long count = 0;
                for(int i = 0;i < nums.size();i++) {
                    count = count + nums[i]/mid;
                }
                return count >= k;
            }
            int maximumCandies(vector<int>& nums, long long k) {
                int low = 1;
                int high = *max_element(nums.begin(),nums.end());
                long long ans = 0;
                while(low <= high) {
                    int mid = low + (high - low) / 2;
                    if(solve(nums,k,mid) == true) {
                        ans = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                return ans;
            }
        };
