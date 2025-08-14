//PROBLEM : 

    You have n dice, and each dice has k faces numbered from 1 to k.
    
    Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers 
      equals target. Since the answer may be too large, return it modulo 109 + 7.



//CODE :  RECURSION


        class Solution {
            int helper(int dice,int faces,int target){
                if(dice==0 && target==0){
                    return 1;
                }else if(dice==0 || target<0){
                    return 0;
                }
                int answer=0;
                for(int i=1;i<=faces;i++){
                    answer = (answer + helper(dice-1,faces,target-i))%1000000007;
                }
                return answer;
            }
        public:
            int numRollsToTarget(int n, int k, int target) {
                return helper(n,k,target);
            }
        };



//CODE : DP 
      class Solution {
          vector<vector<int>> dp;
          int mod = 1000000007;
          int helper(int dice, int faces, int target) {
              if (dice == 0 && target == 0) {
                  return 1;
              } else if (dice == 0 || target < 0) {
                  return 0;
              }
              if (dp[dice][target] != -1)
                  return dp[dice][target];
              int answer = 0;
              for (int i = 1; i <= faces; i++) {
                  answer =
                      (answer + helper(dice - 1, faces, target - i)) % mod;
              }
              return dp[dice][target] = answer;
          }
      
      public:
          int numRollsToTarget(int n, int k, int target) {
              dp.assign(n + 1, vector<int>(target + 1, -1));
              return helper(n, k, target);
          }
      };
      
