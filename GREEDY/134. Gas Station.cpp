//PROBLEM :

      There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
      
      You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next 
        (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
      
      Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit 
      once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.



//APPROACH :
      In the question given that
      If there exists a solution, it is guaranteed to be unique
        -This lines clearly tells us that we have unique or no solution exists

      Here two cases are possible
      
      if our total_gas is less than our total cost in that case we can't complete our journey ,so will return -1
      Now we have a unique solution that means single starting_point exists
      To find that point we will keep track of my current_gas+=gas[i]-cost[i]
      lets suppose at any index our current gas became negative so we can clearly say that till that index all the gas station between ith and starting point are bad, starting point as well.
      So, this means we can start trying at next gas_station on the i+1 station

        
//Complexity
      Time complexity:O(N)
      Space complexity:O(1)


//CODE :
      class Solution {
      public:
          int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
              int gas_sum = 0;
              for (int i : gas)
                  gas_sum += i;
              int cost_sum = 0;
              for (int i : cost)
                  cost_sum += i;
              if ((gas_sum - cost_sum) < 0)
                  return -1;
              int sum = 0;
              int ans = 0;
              for (int i = 0; i < gas.size(); i++) {
                  sum += gas[i] - cost[i];
                  if (sum < 0) {
                      sum = 0;
                      ans = i + 1;
                  }
              }
              return ans;
          }
      };
