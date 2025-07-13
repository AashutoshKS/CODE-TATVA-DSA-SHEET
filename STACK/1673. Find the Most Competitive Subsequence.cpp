//PROBLEM :

      Given an integer array nums and a positive integer k, return the most competitive subsequence of nums of size k.
      
      An array's subsequence is a resulting sequence obtained by erasing some (possibly zero) elements from the array.
      
      We define that a subsequence a is more competitive than a subsequence b (of the same length) if in the first position where a and b differ, 
      subsequence a has a number less than the corresponding number in b. For example, [1,3,4] is more competitive than [1,3,5] because the first 
      position they differ is at the final number, and 4 is less than 5.



//APPROACH :
      if we are left with elements in nums to form k length substring, 
        pop the elemnt from stack if it is greater then the current element

      at the end you will have k elements with highest score



//CODE :
      class Solution {
      public:
          vector<int> mostCompetitive(vector<int>& nums, int k) {
              stack<int>st;
              int n = nums.size();
              for(int i = 0;i < nums.size(); i++) {
                  if(st.empty()) {
                      st.push(nums[i]);
                      continue;
                  }
                  while(!st.empty() && (st.size() + n - i) > k) {
                      if(st.top() > nums[i]) st.pop();
                      else {
                          break;
                      }
                  }
                  st.push(nums[i]);
              }
              vector<int>ans;
              while(!st.empty()) {
                  ans.push_back(st.top());
                  st.pop();
              }
              reverse(ans.begin(),ans.end());
              while(ans.size() > k) ans.pop_back();
              return ans;
          }
      };
