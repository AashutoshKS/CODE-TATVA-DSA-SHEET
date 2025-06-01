//PROBLEM :
        Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.



//APPROACH :
          find all the common elements using map, can also be used to handle dublicate values

//COMPLEXITY :
        TIME COMPLEXITY : O(n)
        SPACE COMPLEXITY : O(1)



//CODE :
        class Solution {
        public:
            vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
                vector<int>ans;
                map<int,int>mp;
                for(int i = 0;i < nums1.size();i++) {
                    if(mp[nums1[i]] == 0) mp[nums1[i]]++; 
                }
                for(int i = 0;i < nums2.size() ;i++) {
                    if(mp[nums2[i]] == 1) {
                        ans.push_back(nums2[i]);
                        mp[nums2[i]] = 0;
                    }
                }
                return ans;
            }
        };
