//PROBLEM :

      Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays
      and you may return the result in any order.


//APPROACH :
        use map for the intersection check since dublicates are allow, no need to handke any special case

//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)


//CODE :
      class Solution {
      public:
          vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
              vector<int>ans;
              map<int,int>mp;
              for(int i = 0 ;i < nums1.size() ;i++) {
                  mp[nums1[i]]++;
              }
              for(int i = 0;i < nums2.size();i++) {
                  if(mp[nums2[i]] > 0) {
                      ans.push_back(nums2[i]);
                      mp[nums2[i]]--;
                  }
              }
              return ans;
          }
      };
