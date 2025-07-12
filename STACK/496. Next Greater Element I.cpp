//PROBLEM :

      The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
      
      You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
      
      For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. 
        If there is no next greater element, then the answer for this query is -1.
      
      Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.



//APPROACH :
        Monotonic stack in nums2, store the values of next greater element 



//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)



//CODE :
      class Solution {
      public:
          vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
              unordered_map<int,int> ans;
              stack <int> v;
              for(int i=nums2.size()-1;i>=0;i--){
                  while(!v.empty() && v.top()<=nums2[i])
                      v.pop();
                  ans[nums2[i]]=(v.empty())?-1:v.top();
                  v.push(nums2[i]);
              }
              for(int i=0;i<nums1.size();i++){
                  nums1[i]=ans[nums1[i]];
              }
              return nums1;
          }
      };
