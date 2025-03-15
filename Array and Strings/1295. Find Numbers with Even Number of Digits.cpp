//PROBLEM : 
  Given an array nums of integers, return how many of them contain an even number of digits.

//complexity 
    TIME COMPLEXITY : O(n);
    SPACE COMPLEXITY : O(1);

//CODE

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=0;
        int dig;
        for(int i=0;i<nums.size();i++){
            dig=log10(nums[i]) + 1;
            if(dig%2 == 0)
                n++;
        }
        return n;
    }
};
