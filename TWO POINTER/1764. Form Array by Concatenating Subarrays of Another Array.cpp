//PROBLEM :

                  You are given a 2D integer array groups of length n. You are also given an integer array nums.
                  
                  You are asked if you can choose n disjoint subarrays from the array nums such that the ith subarray is equal to groups[i] (0-indexed), 
                  and if i > 0, the (i-1)th subarray appears before the ith subarray in nums (i.e. the subarrays must be in the same order as groups).
                  
                  Return true if you can do this task, and false otherwise.
                  
                  Note that the subarrays are disjoint if and only if there is no index k such that nums[k] belongs to more than one subarray. A subarray 
                  is a contiguous sequence of elements within an array.


//APPROACH : 
                  we have to find the continuous concatination of groups in the numse
                  traverse the nums and find the 1st element of the current window(from group vector) where you are 
                  if all the elements from i to window size is equal to the window 
                  move the window 
                  check if you are able to traverse the whole group windows



//COMPLEXITY :
                TIME COMPLEXITY : O(n*n)
                SPACE COMPLEXITY : O(1)



//CODE :
                class Solution {
                public:
                    bool canChoose(vector<vector<int>>& g, vector<int>& nums) {
                        int win = 0;
                        for(int i = 0;i < nums.size(); i++) {
                            if(win == g.size()) break;
                            if(nums[i] == g[win][0]) {
                                int k = 0;
                                int idx = 0,j;
                                for(j = i;j < nums.size();j++,idx++) {
                                    if(idx == g[win].size()) break;
                                    if(g[win][idx] != nums[j]) {
                                        k = 1;
                                        break;
                                    }
                                }
                                if(k == 0 && idx == g[win].size()) {
                                    win++;
                                    i = j - 1;
                                }
                            }
                        }
                        return win == g.size();
                    }
                };
