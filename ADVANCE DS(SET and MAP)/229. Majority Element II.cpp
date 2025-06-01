
//PROBLEM :

      Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.


//APPROACH :
      count frequency if any element if greater than n/3 push to answer



//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)


//CODE :
      class Solution {
      public:
          vector<int> majorityElement(vector<int>& nums) {
              map<int,int> ans;
              vector<int> v;
              int n = nums.size()/3 +1;
              for(int i = 0;i<nums.size();i++){
                  ans[nums[i]]++;
                  if(ans[nums[i]] == n)
                      v.push_back(nums[i]);
              }
              return v;
          }
      };
