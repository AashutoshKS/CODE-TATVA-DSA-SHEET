//PROBLEM :

        You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x
        numbers in nums that are greater than or equal to x.
        
        Notice that x does not have to be an element in nums.
        
        Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.



//CODE :

        class Solution {
        public:
            int specialArray(vector<int>& nums) {
                sort(nums.begin(),nums.end());
                int n=nums.size();
                if(nums[0]>=n)
                return n;
                for(int i=1;i<n;i++){           
                    if(nums[i]==(n-i)){
                        if(nums[i]==nums[i-1])
                        return -1;
                        return nums[i];
                    }
                    
                    if(nums[i]>(n-i)){               
                        if(nums[i-1]==(n-i))
                        return -1;
                        if(nums[i-1]<(n-i))
                        return n-i;                
                    }
                }
                return -1;
            }
        };
        
                  
