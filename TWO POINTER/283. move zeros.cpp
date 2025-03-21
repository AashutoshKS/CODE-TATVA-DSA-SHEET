//problem :
        Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
        
        Note that you must do this in-place without making a copy of the array.

//APPROACH 1 : brute force 
          using 2 pointer 
              1 -> for value != 0
              2 -> the idx where we have to shift the next non zero element
          then change rest of elements to 0


//CODE :
          class Solution {
          public:
              void moveZeroes(vector<int>& nums) {
                  int i=0,j=0;
                  for(i=0,j=0;i<nums.size();){
                      if(nums[i]!=0){
                         nums[j]=nums[i];
                          i++;
                          j++;
                      }
                      else{
                          i++;
                      }
                      
                  }
                  for(i=j;i<nums.size();i++){
                          nums[i]=0;
                      }
                  
              }
          };


//APPROACH 2 :
          solve in 1 run 

//CODE :
        class Solution {
        public:
            void moveZeroes(vector<int>& nums) {
                int j = 0;
                for (int i = 0; i < nums.size(); i++) {
                    if (nums[i] != 0) {
                        swap(nums[i], nums[j]);
                        j++;
                    }
                }        
            }
        };
