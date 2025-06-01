//PROBLEM : 
        
        Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, 
          and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.
        
        Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).
        
        The test cases are generated so that there will be an answer.


//APPROACH : 
          if we divide all the elements from the maximum + 1 or maximum it will give a result of 0 which will be less than thrushold
          we have to check the minimum possible answer within the maximum range
              -> either use linear search from 1 -> max  (complexity O(n*n))
              -> use binary search within the range (complexity O(n*logn))


//COMPLEXITY :
        TIME COMPLEXITY : O(n.logn)
        SPACE COMPLEXITY : O(1)



//CODE :
        class Solution {
        public:
            bool solve(vector<int>& nums, int th,int mid) {
                int count = 0;
                for(int i = 0; i <nums.size();i++) {
                    int x = nums[i];
                    count += (nums[i] + mid - 1) / mid;
                }
                return count <= th;
            }
            int smallestDivisor(vector<int>& nums, int th) {
                int low = 1;
                int high = *max_element(nums.begin(),nums.end());
                int ans = high + 1;
                while ( low <= high) {
                    int mid = low + (high - low)/2;
                    if(solve(nums,th,mid) == true) {
                        ans = min(ans,mid);
                        high = mid - 1;
                    } else{
                        low = mid + 1;
                    }
                }
                return ans;
            }
        };
