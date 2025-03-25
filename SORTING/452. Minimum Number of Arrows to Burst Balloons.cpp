//PROBLEM :

              There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array 
              points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the 
              exact y-coordinates of the balloons.
              
              Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and 
              xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps 
              traveling up infinitely, bursting any balloons in its path.
              
              Given the array points, return the minimum number of arrows that must be shot to burst all balloons.


//APPROACH : 
              This is similar to overlapping intervals which we can determine after sorting the vector
              count the number of non overlapping intervals 


//COMPLEXITY :
              TIME COMPLEXITY : O(n.logn)
              SPACE COMPLEXITY : O(1)


//CODE :
            class Solution {
            public:
                int findMinArrowShots(vector<vector<int>>& nums) {
                    sort(nums.begin(),nums.end());
                    int count = 1;
                    int start = 0;
                    for(int i = 1;i < nums.size();i++) {
                        if(nums[i][0] <= nums[start][1])  {
                            nums[start][1] = min(nums[start][1],nums[i][1]);
                        }
                        else {
                            start = i;
                            count++;
                        }
                    }
                    return count;
                }
            };
