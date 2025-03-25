//PROBLEM :
            You are given an integer array nums and an integer k.
            
            In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.
            
            Return the maximum number of operations you can perform on the array.



//APPROACH : 
              finding pairs with a specific sum is easier when the array is sorted using 2 pointer


//COMPLEXITY : 
              TIME COMPLEXITY : O(n.logn)
              SPACE COMPLEXITY : O(1)



//CODE :
              class Solution {
              public:
                  int maxOperations(vector<int>& nums, int k) {
                      sort(nums.begin(), nums.end());
                      int count = 0;
                      int i = 0, j = nums.size() - 1;
                      while (i < j) {
                          if ((nums[i] + nums[j]) == k) {
                              count++;
                              i++;
                              j--;
                          } else if ((nums[i] + nums[j]) < k)
                              i++;
                          else
                              j--;
                      }
                      return count;
                  }
              };
