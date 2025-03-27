//PROBLEM :

                  You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, 
                    where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:
                  
                  numberOfBoxesi is the number of boxes of type i.
                  numberOfUnitsPerBoxi is the number of units in each box of the type i.
                  You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put
                  on the truck as long as the number of boxes does not exceed truckSize.
                  
                  Return the maximum total number of units that can be put on the truck.


//APPROACH :
                  sort the list on the basis of profit per product
                  greedily pick the most profitable element as much as you can


//COMPLEXITY :
                  TIME COMPLEXITY : O(n.logn)
                  SPACE COMPLEXITY : O(1)


//CODE :
                    class Solution {
                    public:
                        int maximumUnits(vector<vector<int>>& nums, int size) {
                            for(int i = 0;i < nums.size(); i++) {
                                swap(nums[i][0],nums[i][1]);
                            }
                            sort(nums.rbegin(),nums.rend());
                            int ans = 0;
                            for(int i = 0;i < nums.size();i++) {
                                if(nums[i][1] <= size) {
                                    ans += (nums[i][1]*nums[i][0]);
                                    size -= nums[i][1]; 
                                } else {
                                    ans += (nums[i][0]*size);
                                    break;
                                }
                            }
                            return ans;
                        }
                    };
