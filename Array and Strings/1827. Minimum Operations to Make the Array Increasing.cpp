
//PROBLEM : 

  You are given an integer array nums (0-indexed). In one operation, you can choose an element of the array and increment it by 1.
  
  For example, if nums = [1,2,3], you can choose to increment nums[1] to make nums = [1,3,3].
  Return the minimum number of operations needed to make nums strictly increasing.
  
  An array nums is strictly increasing if nums[i] < nums[i+1] for all 0 <= i < nums.length - 1. An array of length 1 is trivially strictly increasing.


//APPROACH

  For min number of operation  if arr[i] <= arr[i - 1].....the minimum operation to make arr[i-1] > arr[i] is to make arr[i-1] = arr[i] + 1
  follow the same staps to calculate total number of operations

TIME COMPLEXITY : O(n)
SPACE COMPLEXITY : O(1)

//code

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        for(int i = 1;i < nums.size(); i++) {
            if(nums[i] <= nums[i-1]) {
                count += nums[i-1] + 1 - nums[i];
                nums[i] = nums[i-1] + 1;
            }
        }
        return count;
    }
};
