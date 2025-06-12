//PROBLEM :
    
    Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
    
    Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.


//APPROACH :
      Find the maximum frequency elements
      and check the distance between the 1st and last index of all the element with maximum frequency



//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)



//CODE :
      class Solution {
      public:
          int findShortestSubArray(vector<int>& nums) {
              unordered_map<int,vector<int>>mp1;
              for(int i = 0; i < nums.size(); i++) {
                  mp1[nums[i]].push_back(i);
              }
              int ans = INT_MIN;
              for(auto it : mp1) {
                  int size = it.second.size();
                  ans = max(size, ans);
              }
              int fin = INT_MAX;
              for(auto it : mp1) {
                  if(it.second.size() == ans) {
                      fin = min(fin,it.second.back() - it.second[0] + 1);
                  }
              }
              return fin;
          }
      };
