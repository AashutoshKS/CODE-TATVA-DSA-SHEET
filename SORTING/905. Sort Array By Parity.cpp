//PROBLEM :
              Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
              
              Return any array that satisfies this condition.


//APPROACH :
              there is no relative order you just have to separate odd and even number
              thus whenever you encounter an even number ush at the start or at the end


//CODE :


              class Solution {
              public:
                vector<int> sortArrayByParity(vector<int>& nums) {
                    int i = 0, j = nums.size() - 1;
                    vector<int>ans(nums.size());
                    for(int k = 0;k < nums.size();k++) {
                        if(nums[k]%2 == 0) {
                            ans[i] = nums[k];
                            i++;
                        } else {
                            ans[j] = nums[k];
                            j--;
                        }
                    }
                    return ans;
                }
            };


//APPROACH 2:
          We can also use 2 pointer logic to solve it


//CODE :
          class Solution {
          public:
              vector<int> sortArrayByParity(vector<int>& nums) {
                  int i = 0, j = nums.size() - 1;
                  while(i < j) {
                      if(nums[i]%2 != 0 && nums[j]%2 == 0) {
                          swap(nums[i],nums[j]);
                          i++;
                          j--;
                      }
                      if(nums[i]%2 == 0) i++;
                      if(nums[j]%2 != 0) j--;
                  }
                  return nums;
              }
          };
