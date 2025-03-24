//PROBLEM :
            Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
            
            In one move, you can increment or decrement an element of the array by 1.
            
            Test cases are designed so that the answer will fit in a 32-bit integer.


//APPROACH :
              for minimum moves we have to change number minimum times which is changing number to the median
              thus we find the median and then number of moves to change a number to the median

 
//CODE :

            class Solution {
            public:
                int minMoves2(vector<int>& nums) {
                    int count = 0, median;
                    int n = nums.size();
                    sort(nums.begin(), nums.end());
                    median = nums[n / 2];
                    for (int i = 0; i < nums.size(); i++) {
                        count += abs(nums[i] - median);
                    }
                    return count;
                }
            };
