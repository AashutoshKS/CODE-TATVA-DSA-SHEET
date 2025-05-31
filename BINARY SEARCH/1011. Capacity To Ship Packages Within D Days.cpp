//PROBELEM :
      A conveyor belt has packages that must be shipped from one port to another within days days.
      
      The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt 
      (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
      
      Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.


//APPROACH :
      here for best case we will require the capacity equal to the maximum weight
      in worst case if we have only one day then we have to have a capacity of sum of all the block 
      use binary search for the range max -> sum


//COMPLEXITY :
      TIME COMPLEXITY : O(n.logn)
      SPACE COMPLEXITY : O(1)


//CODE :
        class Solution {
        public:
            bool solve(vector<int>& weights, int days, int mid) {
                int count = 1;
                int sum = 0;
                for (int i = 0; i < weights.size(); i++) {
                    sum += weights[i];
                    if (sum > mid) {
                        count++;
                        sum = weights[i];
                    }
                }
                return count <= days;
            }
            int shipWithinDays(vector<int>& weights, int days) {
                int sum = 0;
                for (int i = 0; i < weights.size(); i++)
                    sum += weights[i];
                int low = *max_element(weights.begin(), weights.end());
                int high = sum;
                int ans = INT_MAX;
                while (low <= high) {
                    int mid = high + (low - high) / 2;
                    if (solve(weights, days, mid) == true) {
                        ans = min(ans, mid);
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                return ans;
            }
        };
