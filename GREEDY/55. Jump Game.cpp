//PROBLEM :

      You are given an integer array nums. You are initially positioned at the array's first index, 
        and each element in the array represents your maximum jump length at that position.
      
      Return true if you can reach the last index, or false otherwise.



//APPROACH : BRUTE FORCE
      from an index move to all the position one by one adding 1 to the number of move

//CODE :
      class Solution {
      public:
          bool canJump(vector<int>& nums) {
              vector<int> fin(nums.size(), 0);
              fin[0] = 1;
              for (int i = 0; i < nums.size(); i++) {
                  int k = nums[i];
                  if (fin[i] == 0) {
                      return false;
                  }
                  while (k > 0) {
                      if ((i + k) < nums.size()) {
                          fin[i + k]++;
                      } else
                          ;
      
                      k--;
                  }
              }
              return true;
          }
      };



//APPROACH 2 : GREEDY
      Use a maxInd variable to keep track of the pointer's range.
      
      At every index, update the range or reach of this pointer.
      
      After the while loop terminates, check if it terminated before traversing the whole vector.


//CODE :

      class Solution {
      public:
          bool canJump(vector<int>& nums) {
              int maxInd = 0;
              int n = nums.size();
      
              int i = 0;
      
              while(i<n && i<=maxInd){
                  maxInd = max(maxInd,i+nums[i]);
                  i++;
              }
      
              if(i<n) return false;
              
              return true;
          }
      };
