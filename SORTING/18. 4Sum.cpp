//PROBLEM :
           Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
          
          -> 0 <= a, b, c, d < n
          -> a, b, c, and d are distinct.
          -> nums[a] + nums[b] + nums[c] + nums[d] == target
          You may return the answer in any order.



//APPROACH :
             extension of 3 sum problem using 2 pointer after 2 for loops



//CODE :
            class Solution {
            public:
                vector<vector<int>> fourSum(vector<int>& nums, int target) {
                    vector<vector<int>> ans;
                    sort(nums.begin(), nums.end());
                    int n = nums.size();
                    for (int i = 0; i < nums.size(); i++) {
                        if (nums[i] >= target && target >= 0 && nums[i] != 0) {
                            break;
                        }
                        if (i > 0 && nums[i] == nums[i - 1])
                            continue;
                        for (int j = i + 1; j < nums.size(); j++) {
                            if ((nums[i] + nums[j]) >= target && target >= 0 &&
                                (nums[i] + nums[j]) != 0) {
                                break;
                            }
                            if (j > i + 1 && nums[j] == nums[j - 1])
                                continue;
                            int k = j + 1;
                            int l = n - 1;
                            if (target < 0 && nums[l] < target) {
                                continue;
                            }
                            while (k < l) {
                                long long sum = nums[i];
                                sum += nums[j];
                                sum += nums[k];
                                sum += nums[l];
                                if (sum < target) {
                                    k++;
                                } else if (sum > target) {
                                    l--;
                                } else {
                                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                                    ans.push_back(temp);
                                    k++;
                                    l--;
                                    while (k < l && nums[k] == nums[k - 1]) {
                                        k++;
                                    }
                                    while (k < l && nums[l] == nums[l + 1]) {
                                        l--;
                                    }
                                }
                            }
                        }
                    }
                    return ans;
                }
            };
