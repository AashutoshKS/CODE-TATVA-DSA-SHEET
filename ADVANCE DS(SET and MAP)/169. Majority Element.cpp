//PROBLEM :
        Given an array nums of size n, return the majority element.
        
        The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.


//APPROACH 1: Sorting
        it is given that the list contains 1 majority element 
        if the array is sorted the middle one will always be the majority element


//COMPLEXITY :
        TIME COMPLEXITY : O(n.logn)
        SPACE COMPLEXITY : O(1)


//CODE :
          class Solution {
          public:
              int majorityElement(vector<int>& nums) {
                  sort(nums.begin(), nums.end());
                  return nums[nums.size()/2];
              }
          };



-----------------------------------------------------------------------------------------------------------------------------------------------------------

//APPROACH 2 : linear search and count

//COMPLEXITY :
        TIME COMPLEXITY : O(n)
        SPACE COMPLEXITY : O(n)  

------------------------------------------------------------------------------------------------------------------------------------------------------

//APPROACH 3 : Using Moore's Voting Algorithm- O(n) Time and O(1) Space
    This is a two-step process:

        1 -> The first step gives the element that may be the majority element in the array. If there is a majority element in an array, 
          then this step will definitely return majority element, otherwise, it will return candidate for majority element.
        2 -> Check if the element obtained from the above step is the majority element. This step is necessary as there might be no majority element


//COMPLEXITY :
        TIME COMPLEXITY : O(n)
        SPACE COMPLEXITY : O(1)  


//CODE :
        class Solution {
        public:
            int majorityElement(vector<int>& nums) {
                int ans = nums[0];
                int count  =1;
                for(int i = 1;i < nums.size(); i++) {
                    if(nums[i] == ans) count++;
                    else count--;
                    if(count == 0) {
                        count = 1;
                        ans = nums[i];
                    }
                }
                return ans;
            }
        };
