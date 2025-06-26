//PROBLEM :

      There are n projects numbered from 0 to n - 1. You are given an integer array milestones where each milestones[i] denotes the number of milestones the ith project has.
      
      You can work on the projects following these two rules:
      
      Every week, you will finish exactly one milestone of one project. You must work every week.
      You cannot work on two milestones from the same project for two consecutive weeks.
      Once all the milestones of all the projects are finished, or if the only milestones that you can work on will cause you to violate the above rules, you will stop working. Note that you may not be able to finish every project's milestones due to these constraints.
      
      Return the maximum number of weeks you would be able to work on the projects without violating the rules mentioned above.


//APPROACH :
      we can always solve the all the works unless the (total sum - max_num) > maximum number
      is that exception case we can only solve 2*(total sum - max_num) + 1 ops



//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(1)


//CODE :
      class Solution {
      public:
          long long numberOfWeeks(vector<int>& nums) {
              int n = nums.size();
              long long gre = *max_element(nums.begin(), nums.end());
              if(n == 1) return 1;
              long long sum = 0;
              for(int i = 0; i < n; i++) {
                  sum += nums[i];
              }
              sum -= gre;
              if(sum >= gre) return sum + gre;
              return 2*sum + 1;
          }
      };
