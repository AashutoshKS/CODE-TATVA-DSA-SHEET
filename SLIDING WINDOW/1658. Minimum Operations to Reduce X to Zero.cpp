//PROBLEM :

                You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element 
                from the array nums and subtract its value from x. Note that this modifies the array for future operations.
                
                Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.



//APPROACH : SLIDING WINDOW
                we want to find minimum corner elements that sum up to x
                -> find the sum of the elements in the list, and convert the question to MAXIMUM LENGHT WITH SUM K
                  where k = sum - x;



//COMPLEXITY :
                TIME COMPLEXITY : O(2*n) = O(n)
                SPACE COMPLEXITY : O(1)


                  
//CODE :
                class Solution {
                public:
                    int minOperations(vector<int>& nums, int x) {
                        int sum = 0;
                        for (int i = 0; i < nums.size(); i++) {
                            sum += nums[i];
                        }
                        if (sum < x) {
                            return -1;
                        }
                        if (sum == x) {
                            return nums.size();
                        }
                        x = sum - x;
                        int max_len = 0, sums = 0;
                        for (int i = 0, j = 0; j < nums.size(); j++) {
                            sums += nums[j];
                            while (sums > x) {
                                sums -= nums[i];
                                i++;
                            }
                            if (sums == x) {
                                int len = j - i + 1;
                                max_len = max(max_len, len);
                            }
                        }
                        return max_len == 0 ? -1 : nums.size() - max_len;
                    }
                };
                
                                
                                 
