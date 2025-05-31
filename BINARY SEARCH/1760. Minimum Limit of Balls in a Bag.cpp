//PROBLEM :
      You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.
      
      You can perform the following operation at most maxOperations times:
      
      Take any bag of balls and divide it into two new bags with a positive number of balls.
      For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
      Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.
      
      Return the minimum possible penalty after performing the operations.



//APPROACH : 
        in worst case we may not be able to divide the bag ie ans = maximum 
        in best case you can change all the box to 1 ie ans = 1

        Thus the range becomes 1 -> maximum
        use binary search to check which of the possible values can be achieved sucessfully



//COMPLEXITY : 
        TIME COMPLEXITY : O(n.logn)
        SPACE COMPLEXITY : O(1)


        
//CODE :
        class Solution {
        public:
            int call(vector<int>& nums, int maxOperations, int mid) {
                int op = 0;
                for (int i = 0; i < nums.size(); i++) {
                    op += ((nums[i] + mid - 1) / mid) - 1;
                }
                return op;
            }
            int minimumSize(vector<int>& nums, int maxOperations) {
                int low = 1;
                int high = *max_element(nums.begin(), nums.end());
                int ans = INT_MAX;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (call(nums, maxOperations, mid) <= maxOperations) {
                        if (mid < ans) ans = mid;
                        high = mid - 1;
                    } else
                        low = mid + 1;
                }
                return ans;
            }
        };
