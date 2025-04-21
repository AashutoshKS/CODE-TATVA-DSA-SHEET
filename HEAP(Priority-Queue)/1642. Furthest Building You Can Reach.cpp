//PROBLEM :
        
        You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.
        
        You start your journey from building 0 and move to the next building by possibly using bricks or ladders.
        
        While moving from building i to building i+1 (0-indexed),
        
        If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
        If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
        Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.


//APPROACH :
        Since ladder can be use for any height, for efficiency we should use it for the maximum height
        Use this logic to compute the farthest point


//COMPLEXITY :
        TIME COMPLEXITY : O(n)
        SPACE COMPLEXITY : O(n)


//CODE :
        class Solution {
        public:
            int furthestBuilding(vector<int>& nums, int b, int l) {
                int i;
                priority_queue<int, vector<int>, greater<>> pq;
                for (i = 1; i < nums.size(); i++) {
                    if (nums[i] > nums[i - 1]) {
                        int val = (nums[i] - nums[i - 1]);
                        pq.push(val);
                        if (pq.size() > l) {
                            b -= pq.top();
                            pq.pop();
                            if (b < 0) {
                                break;
                            }
                        }
                    }
                }
                return i - 1;
            }
        };
