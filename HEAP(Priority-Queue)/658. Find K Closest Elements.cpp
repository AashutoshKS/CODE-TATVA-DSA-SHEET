//PROBLEM 
        Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
        
        An integer a is closer to x than an integer b if:
        
        |a - x| < |b - x|, or
        |a - x| == |b - x| and a < b


//APPROACH :
        -> Find all the distance and store them in a max heap of size k (for k closest elements)
            distance is equal to abs(x - nums[i])
        -> push the elements of heap in ans and sort it 


//COMPLEXITY :
        TIME COMPLEXITY : O(n.logn)
        SPACE COMPLEXITY : O(k)


//CODE :
        class Solution {
        public:
            vector<int> findClosestElements(vector<int>& nums, int k, int x) {
                priority_queue<pair<int,int>>pq;
                for(int i = 0;i < nums.size(); i++) {
                    int dis = abs(x - nums[i]);
                    pq.push({dis,i});
                    if(pq.size() > k) pq.pop();
                }
                vector<int>ans;
                while(!pq.empty()) {
                    ans.push_back(nums[pq.top().second]);
                    pq.pop();
                }
                sort(ans.begin(),ans.end());
                return ans;
            }
        };
