//PROBLEM : 

      Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.




//APPROACH :
      Since n is small we can use next_permutation STL which takes n.logn in backend which you can implement
      for len n there will me n! permutations



//CODE :
      class Solution {
        public:
            vector<vector<int>> permuteUnique(vector<int>& nums) {
                int num = 1;
                int n = nums.size();
                for(int i = 1;i <= n;i++) {
                    num*=i;
                }
                set<vector<int>>st;
                vector<vector<int>>ans;
                for(int i = 0 ;i < num ;i++) {
                    int n1 = st.size();
                    st.insert(nums);
                    if(st.size() != n1) 
                        ans.push_back(nums);
                    next_permutation(nums.begin(),nums.end());
                }
                return ans;
            }
        };



//APPROACH 2:
      Check all possibilities by keeping a track of used elements....




//CODE :
         class Solution {
            public:
                set<vector<int>>st;
                int n;
                void solve(vector<int>& curr, vector<int>& nums, vector<int>& used) {
                    if(curr.size() == n) {
                        st.insert(curr);
                        return ;
                    }
                    for(int i = 0;i < n; i++) {
                        if(used[i] == 0) {
                            curr.push_back(nums[i]);
                            used[i] = 1;
                            solve(curr, nums, used);
                            curr.pop_back();
                            used[i] = 0;
                        } 
                    }
                }
                vector<vector<int>> permuteUnique(vector<int>& nums) {
                    vector<int>curr;
                    vector<int>used(nums.size());
                    n = nums.size();
                    solve(curr, nums, used);
                    vector<vector<int>>ans(st.begin(), st.end());
                    return ans;
                }
            };
