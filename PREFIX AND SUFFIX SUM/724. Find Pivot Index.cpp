//PROBLEM :
        Given an array of integers nums, calculate the pivot index of this array.
        The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
        If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
    
        Return the leftmost pivot index. If no such index exists, return -1.


//COMPLEXITY : 
        TIME COMPLEXITY : O(3*n) = O(n)
        SPACE COMPLEXITY : O(1)

//CODE :
        class Solution {
        public:
            int pivotIndex(vector<int>& nums) {
                vector<int>left_sum(nums.size());
                int sum=0;
                for(int i=0;i<nums.size();i++){
                    sum+=nums[i];
                    left_sum[i]=sum;
                }
                if(nums.size()==1){
                    return 0;
                }
                for(int i=nums.size()-2;i>=0;i--){
                    nums[i]=nums[i]+nums[i+1];
                }
                
                if(nums[1]==0){
                    return 0;
                }
                for(int i=0;i<nums.size()-2;i++){
                    if(left_sum[i]==nums[i+2]){
                        return i+1;
                    }
                }
                if(left_sum[nums.size()-2]==0){
                    return nums.size()-1;
                }
                return -1;
            }
        };
