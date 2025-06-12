//PROBLEM :

      You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got 
        duplicated to another number in the set, which results in repetition of one number and loss of another number.
      
      You are given an integer array nums representing the data status of this set after the error.
      
      Find the number that occurs twice and the number that is missing and return them in the form of an array.


//APPROACH : 
        use the formula for sum of intergers from 1 - n


//CODE :
      class Solution {
      public:
          vector<int> findErrorNums(vector<int>& nums) {
              int n=nums.size();
              int sum=(n*(n+1))/2;
              int v;
              sort(nums.begin(),nums.end());
              int sum1=0;
              for(int i=0;i<nums.size()-1;i++){
                  if(nums[i]==nums[i+1])
                  v=nums[i];
                  sum1+=nums[i];
              }
              sum1+=nums[n-1];
              return {v,sum-sum1+v};
          }
      };
