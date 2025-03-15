//PROBLEM :
        Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
        
        The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
        
        You must write an algorithm that runs in O(n) time and without using the division operation.

//APPROACH 1 : BRUTE FORCE
        the brute force will be 
        i) Caluculate the product and number of zero
        ii) if num of zero is > 1 the ans will be 0 for all case
        iii) in case of 1 zero find product of rest of the numbers
        iv) for each iteration the val[i] = product / nums[i]

//COMPLEXITY :
        TIME COMPLEXITy : O(3*n) = O(n)
        SPACE COMPLEXITY : O(1)

          
//CODE :
        class Solution {
        public:
            vector<int> productExceptSelf(vector<int>& nums) {
                int product=1,iszero=0;
                for(int i=0;i<nums.size();i++){
                    if(nums[i]==0)
                    iszero++;
                    else
                    product=product*nums[i];
                }
                if(iszero > 1){
                    for(int i=0;i<nums.size();i++){
                        nums[i]=0;
                    }
                }
                else if(iszero==1){
                    for(int i=0;i<nums.size();i++){
                        if(nums[i]==0)
                        nums[i]=product;
                        else
                        nums[i]=0;
                    }
                }
                else{
                    for(int i=0;i<nums.size();i++){
                        nums[i]=product/nums[i];
                    }
                }
                return nums;
            }
        };


//APPROACH 2: USING PREFIX SUM-------------------------------------------------------------------------------------------------------------------------------

        take 2 vector store prefix product and suffix product 
        for eachiteration ans[i] = pre[i-1]*suf[i+1], it neglects the number itself and find the product of other elements


//COMPLEXITY : 
        TIME COMPLEXITY : O(n) 
        SPACE COMPLEXITY : O(2*n) = O(n)


//CODE :
        class Solution {
        public:
            vector<int> productExceptSelf(vector<int>& nums) {
                vector<long long>pre(nums.size()),post(nums.size());
                pre[0] = nums[0];
                for(int i = 1; i < nums.size(); i++) pre[i] = pre[i-1]*nums[i];
                post[nums.size() - 1] = nums[nums.size() - 1];
                for(int i = nums.size() - 2;i >= 0;i--) post[i] = nums[i]*post[i+1];
                nums[0] = post[1];
                nums[nums.size() - 1] = pre[nums.size() - 2];
                for(int i = 1;i <= nums.size() - 2;i++) {
                    nums[i] = pre[i-1]*post[i+1];
                }
                return nums;
            }
        };
