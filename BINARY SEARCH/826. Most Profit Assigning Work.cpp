//PROBLEM :

      You have n jobs and m workers. You are given three arrays: difficulty, profit, and worker where:
      
      difficulty[i] and profit[i] are the difficulty and the profit of the ith job, and
      worker[j] is the ability of jth worker (i.e., the jth worker can only complete a job with difficulty at most worker[j]).
      Every worker can be assigned at most one job, but one job can be completed multiple times.
      
      For example, if three workers attempt the same job that pays $1, then the total profit will be $3. If a worker cannot complete any job, their profit is $0.
      Return the maximum profit we can achieve after assigning the workers to the jobs.



//APPROACH :
        using map we can compute the maximum capacity of any difficulty which is moost suited
        traverse the whole range of map to assign the most suitable worker for that specific difficulty


//CODE :
        class Solution {
        public:
            int maxProfitAssignment(vector<int>& nums, vector<int>& profit, vector<int>& worker) {
                map<int, int> mp;
                int low = nums[0];
                int high = *max_element(worker.begin(),worker.end());
                for (int i = 0; i < nums.size(); i++) {
                    mp[nums[i]] = max(mp[nums[i]], profit[i]);
                    high = max(high, nums[i]);
                    low = min(low, nums[i]);
                }
                for (int i = low; i <= high; i++) {
                    mp[i] = max(mp[i],mp[i-1]);
                }
                int ans = 0;
                for(int i = 0;i < worker.size();i++) {
                    ans += mp[worker[i]];
                }
                return ans;
            }
        };


//APPROACH 2 :
      using greedy

//CODE :

        class Solution {
        public:
            int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
                int maximum = 0;
        
                for(auto& weights : difficulty){
                    maximum = max(maximum, weights);
                }
                vector<int> nums(maximum, 0);
                int size = profit.size();
                for(int i = 0; i < size; i++){
                    nums[difficulty[i] - 1] = max(profit[i],nums[difficulty[i] - 1]);
                }
                for(int i = 1; i < maximum; i++){
                    nums[i] = max(nums[i], nums[i - 1]);
                }
                int totalProfit = 0;
                for(auto& person : worker){
                    totalProfit += person > maximum ? nums[maximum - 1] : nums[person - 1];
                }
                return totalProfit;
            }
        };
