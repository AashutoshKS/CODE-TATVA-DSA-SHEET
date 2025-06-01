//PROBLEM :

      Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.


//APPROACH :
      Count frequency of each number traverse through map to find the if all are unique or not


//COMPLEXITY :
      TIME COMPLEXITY : O(n);
      SPACE COMPLEXITY : O(n)



//CODE :
      class Solution {
      public:
          bool uniqueOccurrences(vector<int>& arr) {
              map<int,int>nums;
              int n=arr.size();
              for(int i=0;i<arr.size();i++){
                  nums[arr[i]]++;
              }
              map<int,int>mp1;
              for(auto & it: nums) {
                  mp1[it.second]++;
                  if(mp1[it.second] > 1) return false;
              }
              return true;
          }
      };
      
       
