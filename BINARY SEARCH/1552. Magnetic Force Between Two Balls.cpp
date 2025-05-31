//PROBLEM :
        In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. 
        Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that 
        the minimum magnetic force between any two balls is maximum.
        
        Rick stated that magnetic force between two different balls at positions x and y is |x - y|.
        
        Given the integer array position and the integer m. Return the required force.
        

//APPROACH :
          In best case the baskets can be alternate with force = 1
          for worst case in case of only 2 basket the maximum possible output will be distance between the maximum and the minimum element
          This the range is from 1 -> (max - min)



//COMPLEXITY :
          TIME COMPLEXITY : O(n.logn)
          SPACE COMPLEXITY : O(1)



//CODE :
          class Solution {
          public:
              bool solve(vector<int>& nums, int m,int mid) {
                  int count = 1;
                  int prev = nums[0];
                  for(int i = 1; i < nums.size(); i++) {
                      if((nums[i] - prev) >= mid) {
                          prev = nums[i];
                          count++;
                      }
                  }
                  return count >= m;
              }
              int maxDistance(vector<int>& nums, int m) {
                  sort(nums.begin(),nums.end());
                  int low = 1;
                  int high = nums.back() - nums[0];
                  int ans = INT_MIN;
                  while(low <= high) {
                      int mid = low + (high - low) / 2;
                      if(solve(nums,m,mid) == true) {
                          ans = max(ans,mid);
                          low = mid + 1;
                      } else {
                          high = mid - 1;
                      }
                  }
                  return ans;
              }
          };
