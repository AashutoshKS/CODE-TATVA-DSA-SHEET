//PROBLEM :
              You are given an integer array nums. In one move, you can pick an index i where 0 <= i < nums.length and increment nums[i] by 1.
              
              Return the minimum number of moves to make every value in nums unique.
              
              The test cases are generated so that the answer fits in a 32-bit integer.


//APPROACH 1 : BRUTE FORCE -> USING HASHMAP

                since the number of moves must be minimum we have to find the min number which is not present in the array
                for the same we use hashmap
                        -> if there are no values in map put in the map
                        -> else check the next greater element which is not present in the map , with each iteration increment the number of moves

//COMPLEXITY :  
            TIME COMPLEXITY  : O(n*n)
            SPACE COMPLEXITY : O(n)


//CODE :
            class Solution {
            public:
                int minIncrementForUnique(vector<int>& nums) {
                    map<int,int>check;
                    int count=0,same=0;
                    for(int i=0;i<nums.size();i++){
                        if(check[nums[i]] == 1){
                            int num=nums[i];
                            while(check[nums[i]] == 1){
                                nums[i]++;
                                count++;
                                if(check[nums[i]]==0){
                                    check[nums[i]]++;
                                    break;
                                }
                            }
                        }else{
                            check[nums[i]]++;
                        }
                    }
                    return count;
                }
            };


//APPROACH 2 : using SORTING
            the same idea can be used here. 
            ie. we have to find the minimum number which is not present in the array for that we sort the array
            and traverse the array from start and make the element as minimum as possible
            ie. either the element itself or element + 1, since we cant decrement the value, and count number of times the value is changed


//COMPLEXITY :  
            TIME COMPLEXITY  : O(n*logn)
            SPACE COMPLEXITY : O(1)


//CODE :
          class Solution {
          public:
              int minIncrementForUnique(vector<int>& nums) {
                  int count = 0;
                  sort(nums.begin(),nums.end());
                  for(int i = 1;i < nums.size(); i++) {
                      if(nums[i] <= nums[i-1]) {
                          count += nums[i-1] + 1 - nums[i];
                          nums[i] = nums[i-1] + 1;
                      } 
                  }
                  return count;
              }
          };
