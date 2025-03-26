//PROBLEM :            
              
          Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.
          
          The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
          
          Return the number of remaining intervals.


//APPROACH :
            check the overlapping intervals and count the intervals which is under the previous interval
            return size - count 



//CODE :
                        
            class Solution {
            public:
                int removeCoveredIntervals(vector<vector<int>>& nums) {
                    sort(nums.begin(),nums.end());
                    int n = nums.size();
                    int count = 0;
                    for(int i = 1; i < nums.size();i++) {
                        if((nums[i][0] >= nums[i-1][0]) && (nums[i][1] <= nums[i-1][1])) {
                            count++;
                            nums[i] = nums[i-1];
                        } else {
                            if(nums[i][0] == nums[i-1][0] && nums[i][1] >= nums[i-1][1]) {
                                count++;
                            } else if(nums[i][0] < nums[i-1][1] && nums[i][1] >= nums[i-1][1]) {
                                nums[i][1] = max(nums[i-1][1],nums[i][1]);
                            }
                        }
                    }
                    return n - count;
                }
            };
