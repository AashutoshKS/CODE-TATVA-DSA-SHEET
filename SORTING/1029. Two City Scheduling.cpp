//PROBLEM :

        A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to 
        city a is aCosti, and the cost of flying the ith person to city b is bCosti.
        
        Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.
        

//APPROACH : 
        Decide the city on the basis of diff betwen city A, city B,
        compute all the difference 
        sort them
        select city B for 1st half, A for the 2nd half


//COMPLEXITY :
        TIME COMPLEXITY : O(n.logn)
        SPACE COMPLEXITY : O(1)


//CODE :
        class Solution {
        public:
            int twoCitySchedCost(vector<vector<int>>& costs) {
                int n = costs.size()/2;
                for(int i = 0; i < costs.size(); i++) {
                    int val = costs[i][1] - costs[i][0];
                    costs[i].insert(costs[i].begin(),val);
                }
                sort(costs.begin(),costs.end());
                int ans = 0;
                for(int i = 0; i <costs.size(); i++) {
                    if(i < n) ans += costs[i][2];
                    else ans += costs[i][1];
                }
                return ans;
            }
        };
