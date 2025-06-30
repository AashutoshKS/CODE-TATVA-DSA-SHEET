//PROBLEM :
      
      You are given an integer array enemyEnergies denoting the energy values of various enemies.
      
      You are also given an integer currentEnergy denoting the amount of energy you have initially.
      
      You start with 0 points, and all the enemies are unmarked initially.
      
      You can perform either of the following operations zero or multiple times to gain points:
      
      Choose an unmarked enemy, i, such that currentEnergy >= enemyEnergies[i]. By choosing this option:
      You gain 1 point.
      Your energy is reduced by the enemy's energy, i.e. currentEnergy = currentEnergy - enemyEnergies[i].
      If you have at least 1 point, you can choose an unmarked enemy, i. By choosing this option:
      Your energy increases by the enemy's energy, i.e. currentEnergy = currentEnergy + enemyEnergies[i].
      The enemy i is marked.
      Return an integer denoting the maximum points you can get in the end by optimally performing operations.



//APPROACH 1: SORTING
      to maximise the result
      always kill the enemy with least power as many times as you can
      use points to increase the power by the maximum power of enemy and remove the maximum by the nums


//COMPLEXITY : 
      TIME COMPLEXITY : O(n.logn)
      SPACE COMPLEXITY : O(1)


//CODE :
      class Solution {
      public:
          long long maximumPoints(vector<int>& nums, int curr) {
              sort(nums.begin(), nums.end());
              long long ans = 0;
              while(nums.size() > 0) {
                  ans += curr/nums[0];
                  curr = curr%nums[0];
                  if(ans > 0) {
                      curr += nums.back();
                      nums.pop_back();
                  } else if(curr < nums[0]) break;
              }
              return ans;
          }
      };        
_____________________________________________________________________________________________________________________


//APPROACH 2 : WITHOUT SORTING
      if minimum is greater than curr power return 0
      else add the elements in power except for the minimum one(only kill the minimum power enemy)


//COMPLEXITY : 
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(1)


      
//CODE :
      class Solution {
      public:
          long long maximumPoints(vector<int>& nums, long long curr) {
              int minimum = *min_element(nums.begin(), nums.end());
              if(curr < minimum) return 0;
              for(int i : nums) curr += (long long)i;
              curr -= minimum;
              return curr/minimum;
          }
      };
