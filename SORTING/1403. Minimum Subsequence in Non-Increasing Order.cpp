
//PROBLEM :
                Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than the sum of the non 
                included elements in such subsequence. 
                
                If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions, 
                return the subsequence with the maximum total sum of all its elements. A subsequence of an array can be obtained by 
                erasing some (possibly zero) elements from the array. 
                
                Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in non-increasing order.


//APPROACH :
                  if we change the order of element.....the sum will not change,
                  this gives the idea that we do not have to find the sub sequence but the least number of elements which satisfies the condition
                  thus, sort the vector and start picking the greatest elements


//CODE :

              class Solution {
              public:
                  vector<int> minSubsequence(vector<int>& nums) {
                      long long sum = 0;
                      for(int i: nums) sum+=i;
                      sort(nums.rbegin(),nums.rend());
                      int sub_sum = 0;
                      vector<int>ans;
              
                      for(int i = 0;i < nums.size();i++) {
                          sub_sum += nums[i];
                          sum -= nums[i];
                          ans.push_back(nums[i]);
                          if(sub_sum > sum) break;
                      }
                      return ans;
                  }
              };
