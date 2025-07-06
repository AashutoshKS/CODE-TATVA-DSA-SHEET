//PROBLEM :

        You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:
        
        Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
        Return the maximum number of points you can earn by applying the above operation some number of times.


//APPROACH :
      key point : if you are selecting any value, make sure you select all its duplicate
        it is like house robber problem
          ie if you have choosen n, ye can not choose n - 1, or n + 1
          use the logic to reach at a point with maximum profit
              either select (n - 1) value
              or (n-2) + nth value


//NOTE : CODE IS WRITTEN IN READABLE FORM, FOR SIMPLE UNDERSTANDING
        YYOU CAN THINK OF REDUCING USE OF MAP OR SET



//CODE :
      class Solution {
      public:
          int deleteAndEarn(vector<int>& nums) {
              unordered_map<int,int> mp;
              for(int i : nums) mp[i] += i;
              set<int> st(nums.begin(), nums.end());
              vector<int> newnums(st.begin(), st.end());
              int n = newnums.size();
              if (n == 0) return 0;
              if (n == 1) return mp[newnums[0]];
              vector<int> dp(n, 0);
              dp[0] = mp[newnums[0]];
              if (newnums[1] == newnums[0] + 1)
                  dp[1] = max(mp[newnums[0]], mp[newnums[1]]);
              else
                  dp[1] = mp[newnums[0]] + mp[newnums[1]];
                  
              for(int i = 2; i < n; i++) {
                  if (newnums[i] == newnums[i-1] + 1)
                      dp[i] = max(dp[i-1], dp[i-2] + mp[newnums[i]]);
                  else
                      dp[i] = dp[i-1] + mp[newnums[i]];
              }
              return dp[n-1];
          }
      };
