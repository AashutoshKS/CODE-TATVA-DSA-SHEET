//PROBLEM :

        Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.


//APPROACH :
        count the frequency of each elements and return the top k elements in sorted order


//CODE:
        class Solution {
        public:
            vector<int> topKFrequent(vector<int>& nums, int k) {
                priority_queue<pair<int,int>>heap;
                sort(nums.begin(),nums.end());
                int count = 1;
                for(int i = 1;i < nums.size();i++) {
                    if(nums[i] == nums[i-1]) {
                        count++;
                    }
                    else {
                        heap.push({count,nums[i-1]});
                        count = 1;
                    }
                }
                heap.push({count,nums.back()});
                vector<int>ans;
                while(k--) {
                    int x = heap.top().second;
                    if(ans.size() > 0 && ans.back() == x) {
                        k++;
                    } else {
                        ans.push_back(x);
                    }
                    heap.pop();
                }
                return ans;
            }
        };
