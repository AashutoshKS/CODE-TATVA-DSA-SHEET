//PROBLEM :

        Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, 
        return the index where it would be if it were inserted in order.
        
        You must write an algorithm with O(log n) runtime complexity.


//APPROACH 1: 
          linear search, the 1st element which is greater or equal to the target


//COMPLEXITY : 
          TIME COMPLEXITY : O(n)
          SPACE COMPLEXITY : O(1)


//CODE :
          class Solution {
          public:
              int searchInsert(vector<int>& nums, int target) {
                  for(int i=0;i<nums.size();){
                      if(nums[i]>=target)
                      return i;
                      else i++;
                  }
                  int n=nums.size();
                  return n;
              }
          };


//APROACH 2:
      use binary search to find the index of 1st element >= target


//COMPLEXITY : 
          TIME COMPLEXITY : O(logn)
          SPACE COMPLEXITY : O(1)
        

//CODE :
         class Solution {
         public:
          int searchInsert(vector<int>& nums, int target) {
            int l = 0;
            int r = nums.size();
        
            while (l < r) {
              const int m = (l + r) / 2;
              if (nums[m] == target)
                return m;
              if (nums[m] < target)
                l = m + 1;
              else
                r = m;
            }
        
            return l;
          }
        };
