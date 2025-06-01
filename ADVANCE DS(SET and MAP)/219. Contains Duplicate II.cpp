//PROBLEM :

    Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that 
    nums[i] == nums[j] and abs(i - j) <= k.

//APPROACH 1 : BRUTE FORCE
      Checking all the possible pairs 
      complexity O(n*n)

--------------------------------------------------------------------------------------------------------------------------------------------------------

//APPROACH 2 : MAP
      use map to store index of elemnt one by one 
      if any number n occurs multiple time upto index m 
        we require the maximum index of the number to have a minimum differece thus we do not have to thing about all the indexes  


//COMPLEXITY : 
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)


//CODE :
      class Solution {
      public:
          bool containsNearbyDuplicate(vector<int>& nums, int k) {
              unordered_map<int,int>check;
              for(int i=0;i<nums.size();i++){
                  if(check[nums[i]] != 0){
                      if((i - check[nums[i]] + 1) <= k){
                          return true;
                      }
                  }
                  check[nums[i]] = i+1;
              }
              return false;
          }
      };
