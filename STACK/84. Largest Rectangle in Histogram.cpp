//PROBLEM :

      Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle 
        in the histogram.



//APPROACH :
      Use monotonic stack from both the sides to deduce the
          next smallest element (index), NSE
          previous smallest element (index) , PSE
      
      
      the maximum area possible from a node....if
        (NSE - PSE - 1)*nums[i]
      
      
      

//COMPLEXITY : 
    TIME COMPLEXITY : O(n)
    SPACE COMPLEXITY : O(n)



//CODE :
      class Solution {
      public:
          int largestRectangleArea(vector<int>& nums) {
              int ans = 0, n = nums.size();
              stack<int>st;
              vector<int>nse(n);
              vector<int>pse(n);
              for(int i = n - 1; i >= 0; i--) {
                  while(!st.empty() && nums[st.top()] >= nums[i]) {
                      st.pop();
                  }
                  if(st.empty()) nse[i] = n;
                  else nse[i] = st.top();
                  st.push(i);
              }
              while(!st.empty()) st.pop();
              for(int i = 0; i < n; i++) {
                  while(!st.empty() && nums[st.top()] >= nums[i]) {
                      st.pop();
                  }
                  if(st.empty()) pse[i] = -1;
                  else pse[i] = st.top();
                  st.push(i);
              }
              for(int i = 0;i < n;i++) {
                  ans = max(ans, (nse[i] - pse[i] - 1)*nums[i]);
              }
              return ans;
          }
      };
