//PROBLEM :


            Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
            
            Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows
            
                  a, b are from arr
                  a < b
                  b - a equals to the minimum absolute difference of any two elements in arr


//APPROACH :
          -> 1st sort the vector an element will have min difference with its next element since vector is sorted
          -> compute the minimum difference 
          -> return the pairs with minimum difference


//CODE :
          class Solution {
          public:
              vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
                  sort(nums.begin(),nums.end());
                  int min_diff = INT_MAX;
                  for(int i = 0; i < nums.size() - 1; i++) {
                      min_diff = min(min_diff,nums[i+1] - nums[i]);
                  }
                  vector<vector<int>>ans;
                  for(int i = 0; i < nums.size() - 1; i++) {
                      if(nums[i+1] - nums[i] == min_diff) {
                          ans.push_back({nums[i],nums[i+1]});
                      }
                  }
                  return ans;
              }
          };
