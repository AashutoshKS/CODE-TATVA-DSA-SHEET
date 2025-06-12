//PROBLEM :

      There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" 
        and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.
      
      Given the array answers, return the minimum number of rabbits that could be in the forest.
      


//APPROACH :
      We have to return the minimum
      so if n person says that there are n more rabbits of same colour then the minimum will be n + 1
        use this property for solving

//COMPLEXITY :
    The solution uses a set then convert it to vector
    Try to reduce that extra space by solving in runtime

//CODE :
      class Solution {
      public:
          int numRabbits(vector<int>& nums) {
              unordered_map<int, int> mp;
              for (int i = 0; i < nums.size(); i++) {
                  mp[nums[i]]++;
              }
              unordered_set<int> st(nums.begin(), nums.end());
              vector<int> nums2(st.begin(), st.end());
              int ans = 0;
              for (int i = 0; i < nums2.size(); i++) {
                  if (nums2[i] == 0) {
                      ans += mp[0];
                  } else if (mp[nums2[i]] <= nums2[i] + 1) {
                      ans += nums2[i] + 1;
                  } else {
                      mp[nums2[i]] -= nums2[i] + 1;
                      ans += nums2[i] + 1;
                      i--;
                  }
              }
              return ans;
          }
      };
