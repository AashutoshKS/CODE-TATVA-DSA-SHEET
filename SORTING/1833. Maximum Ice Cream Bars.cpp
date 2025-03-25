//PROBLEM :
              It is a sweltering summer day, and a boy wants to buy some ice cream bars.
              
              At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. 
              The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 
              
              Note: The boy can buy the ice cream bars in any order.
              
              Return the maximum number of ice cream bars the boy can buy with coins coins.
              
              You must solve the problem by counting sort.


//APPROACH :
              to pick more elements we have to pick the smallest elements
              sort and pick elements from the beginning as much as you can


//CODE :
            class Solution {
            public:
                int maxIceCream(vector<int>& costs, int coins) {
                    sort(costs.begin(), costs.end());
                    int sum = 0;
                    int count = 0;
                    for (int i = 0; i < costs.size(); i++) {
                        sum += costs[i];
                        if (sum > coins) {
                            return count;
                        }
                        count++;
                    }
                    return count;
                }
            };
            
            
            
            
