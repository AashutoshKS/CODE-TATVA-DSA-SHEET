//PROBLEM : 

      You are the manager of a basketball team. For the upcoming tournament, you want to choose the team with the highest overall score. 
          The score of the team is the sum of scores of all the players in the team.
      
      However, the basketball team is not allowed to have conflicts. A conflict exists if a younger player has a strictly higher score than an older player. 
          A conflict does not occur between players of the same age.
      
      Given two lists, scores and ages, where each scores[i] and ages[i] represents the score and age of the ith player, respectively, 
          return the highest overall score of all possible basketball teams.



//APPROACH :
      Sort the ages(increasing), and score(decreasing for same rank)
      choose all the previous score which are smaller than the current score, rank will always be maintained
        ie scores = [4,5,6,5], ages = [2,1,2,1]
        sort as
            Ages    1 1 2 2
            scores  5 5 6 4


//CODE :
      class Solution {
      public:
          int bestTeamScore(vector<int>& scores, vector<int>& ages) {
              vector<vector<int>> nums;
              for (int i = 0; i < ages.size(); i++) {
                  nums.push_back({ages[i], scores[i]});
              }
              sort(begin(nums), end(nums), [](const auto& a, const auto& b) {
                  return a[0] == b[0] ? a[1] > b[1] : a[0] > b[0];
              });
              vector<int> ans(nums.size(), 0);
              int fin = 0;
              for (int i = 0; i < nums.size(); ++i) {
      
                  ans[i] = nums[i][1];
      
                  for (int j = 0; j < i; ++j) {
                      if (nums[j][1] >= nums[i][1]) {
                          ans[i] = max(ans[i], ans[j] + nums[i][1]);
                      }
                  }
      
                  fin = max(fin, ans[i]);
              }
              return fin;
          }
      };
