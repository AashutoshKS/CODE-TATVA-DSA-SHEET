//PROBLEM :
            Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.


//APPROACH :
              Since after n rotation we will get the same array thus k = k % n
              reverse the array from start to k, then k to end then start to end to get the resultant array

//COMPLEXITY : 
              TIME COMPLEXITY : O(2*n) = O(n)
              SPACE COMPLEXITY : O(1)

              
//CODE : USING STL 
              class Solution {
              public:
                  void rotate(vector<int>& nums, int k) {
                      k = k % nums.size();
                      reverse(nums.begin(),nums.end());
                      reverse(nums.begin(),nums.begin() + k);
                      reverse(nums.begin() + k,nums.end());
                  }
              };

//CODE: USING TWO POINTER : for reversal
              class Solution {
              public:
                  void rotate(vector<int>& nums, int k) {
                      k=k%nums.size();
                      int m=k;
                      int i=0;
                      int n=nums.size()-1,j = n;
                      while(i < j) {
                          int temp=nums[i];
                          nums[i]=nums[j];
                          nums[j]=temp;
                          i++;
                          j--;
                      }
                      i = 0;
                      while(i<k-1){
                          int temp=nums[i];
                          nums[i]=nums[k-1];
                          nums[k-1]=temp;
                          i++;
                          k--;
                      }
                      while(m<n){
                          int temp=nums[m];
                          nums[m]=nums[n];
                          nums[n]=temp;
                          m++;
                          n--;
                      }
                  }
              };
