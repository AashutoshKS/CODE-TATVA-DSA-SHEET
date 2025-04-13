//PROBLEM :

                There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

                In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
                
                Your score is the sum of the points of the cards you have taken.
                
                Given the integer array cardPoints and the integer k, return the maximum score you can obtain.




//APPROACH : 
              since we can only take the cards from the end or beginning
              we can conclude that our answer will be complete array - a subarray from the middle
              where since we can select k elements therefor the lenght of subarray will be size of array - k
              
              
              The question can be chnages to find the subarray of lenght(size - k) with min sum
              since if we remove a minimum sum from a whole 
              the let out is the maximum
              
              question thus changes to 
              find minimum subarray ith size lenght - k with minimum sum
              
              return total sum - subarray sum
              



//COMPLEXITY :
                TIME COMPLEXITY : O(n);
                SPACE COMPLEXITY : O(3) = O(1);


//CODE :

                class Solution {
                public:
                    int maxScore(vector<int>& nums, int k) {
                        k = nums.size() - k;
                        int sum = 0;
                        int in_sum = 0;
                        int max_sum = INT_MAX;
                        for(int i = 0, j = 0; j < nums.size(); j++) {
                            sum += nums[j];
                            in_sum += nums[j];
                            if((j - i + 1) > k) {
                                in_sum -= nums[i];
                                i++;
                            }
                            if((j - i + 1) == k) {
                                max_sum = min(max_sum, in_sum);
                            }
                        }
                        return sum - max_sum;
                    }
                };



