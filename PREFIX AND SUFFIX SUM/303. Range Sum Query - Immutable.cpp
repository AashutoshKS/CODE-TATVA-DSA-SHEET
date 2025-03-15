//PROBLEM :
        Given an integer array nums, handle multiple queries of the following type:
        
        Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
        Implement the NumArray class:
        
        NumArray(int[] nums) Initializes the object with the integer array nums.
        int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive 
        (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

//COMPLEXITY : 
        TIME COMPLEXITY : O(n)
        SPACE COMPLEXITY : O(n)


//CODE :
        class NumArray {
        public:
            vector<int>nums1;
            NumArray(vector<int>& nums) {
                nums1.push_back(nums[0]);
                for(int i = 1;i < nums.size();i++) {
                    nums[i] = nums[i-1] + nums[i];
                    nums1.push_back(nums[i]);
                }
            }
            
            int sumRange(int left, int right) {
                if(left == 0) return nums1[right];
                return nums1[right] - nums1[left - 1];
            }
        };
