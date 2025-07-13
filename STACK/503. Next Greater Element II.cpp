//PROBLEM :

      Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
      
      The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find 
      its next greater number. If it doesn't exist, return -1 for this number.



//APPROACH :
      Since its a circular array, create a list of repeated nums
          ie new list = nums + nums
      use stack, (monotonic stack) to compute the next greatest element



//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)



//CODE :
    class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
           int n=nums.size();
           vector<int>ans1(n);
           for(int i=0;i<n;i++){
                nums.push_back(nums[i]);
            }
            stack<int>ans;
            for(int i=nums.size()-1;i>=0;i--){
                while(!ans.empty() && ans.top()<=nums[i]){
                    ans.pop();
                }
                if(i<n){
                    ans1[i]=ans.empty()?-1:ans.top();
                }
                ans.push(nums[i]);
            }
            return ans1;
        }
    };
