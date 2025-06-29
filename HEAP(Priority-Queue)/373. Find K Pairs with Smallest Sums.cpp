//PROBLEM :

      You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.
      
      Define a pair (u, v) which consists of one element from the first array and one element from the second array.
      
      Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.


//APPROACH :
      the sum of 1st element will always be minimum 
      ie element at indest {0,0} after that we the next minimum will be either {0,1} or {1,0} 
        ie {prev1 + 1, prev2} or {prev1, prev2+ 1} 
      use min heap to find the minimum sum handel the out of bound case and also duplicate values using map


//COMPLEXITY :
      TIME COMPLEXITY : O(n.logn)
      SPACE COMPLEXITY : O(3*n + 3*n) = O(n)


//CODE 
      class Solution {
      public:
          vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
              long long sum = nums1[0] + nums2[0];
              vector<vector<int>>ans;
              map<pair<int,int>,int>mp;
              priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<>>q;
              q.push({sum,{0,0}});
              while(k > 0) {
                  pair<int,pair<int,int>> curr = q.top();
                  q.pop();
                  int idx1 = curr.second.first;
                  int idx2 = curr.second.second;
                  ans.push_back({nums1[idx1], nums2[idx2]});
                  if((idx1 + 1) < nums1.size()) {
                      if(mp[{idx1 + 1, idx2}] == 0) 
                          q.push({nums1[idx1 + 1] + nums2[idx2], {idx1 + 1, idx2}});
                      mp[{idx1 + 1, idx2}]++;
                  }
                  if((idx2 + 1) < nums2.size()) {
                      if(mp[{idx1, idx2 + 1}] == 0)
                          q.push({nums1[idx1] + nums2[idx2 + 1], {idx1, idx2 + 1}});
                      mp[{idx1, idx2 + 1}]++;
                  }
                  k--;
              }
              return ans;
          }
      };
              
