//PROBLEM :
            Sort 0,1,2 


              
//APPROACH : 
            use sorting STL

//COMPLEXITY :
            SPACE COMPLEXITY : O(1)
            TIME COMPLEXITY : O(n.logn)

//CODE :
            class Solution {
            public:
                void sortColors(vector<int>& nums) {
                    sort(nums.begin(),nums.end());
                }
            };


//APPROACH : 
          take 3 pointers
                ->idx to move forward
                -> start to put 0 in strating
                -> end to push 2 at the end
          if at any idx val == 0 swap with start (start++) if at any idx value is 2 swap with the end (end--)

            
//COMPLEXITY :
            SPACE COMPLEXITY : O(3) = O(1)
            TIME COMPLEXITY : O(n)


//CODDE :
          class Solution {
          public:
              void sortColors(vector<int>& nums) {
                  int start = 0, index = 0;
                  int end = nums.size() - 1;
                  while (index <= end) {
                      if (nums[index] == 0) {
                          swap(nums[index], nums[start]);
                          ++index;
                          ++start;
                      } else if (nums[index] == 1) {
                          ++index;
                      } else {
                          swap(nums[index], nums[end]);
                          --end;
                      }
                  }
              }
          };
