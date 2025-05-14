//PROBLEM :

      You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] means that 
      the i​​​​​​th​​​​ task will be available to process at enqueueTimei and will take processingTimei to finish processing.
      
      You have a single-threaded CPU that can process at most one task at a time and will act in the following way:
      
      If the CPU is idle and there are no available tasks to process, the CPU remains idle.
      If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. If multiple tasks have the same 
      shortest processing time, it will choose the task with the smallest index.
      Once a task is started, the CPU will process the entire task without stopping.
      The CPU can finish a task then start a new one instantly.
      Return the order in which the CPU will process the tasks.
      

//APPROACH :
    -> For each time pick all the process which are ready
    -> out of that ready elements list take the element with the least processing time
    -> since we do not require the arrival time in case 2 use the data structure accordinglt
      take 2 priority queues and push all the process one by one


//CODE :


      class Solution {
      public:
          vector<int> getOrder(vector<vector<int>>& tasks) {
              int n = tasks.size();
              priority_queue<pair<pair<long long, long long>, int>, vector<pair<pair<long long, long long>, int>>, greater<pair<pair<long long, long long>, int>>> time;
              
              priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>> aval;
      
              for (int i = 0; i < n; ++i) {
                  time.push({{tasks[i][0], tasks[i][1]}, i});
              }
      
              vector<int> ans;
              long long t = time.top().first.first; 
              while (!time.empty() || !aval.empty()) {
                  while (!time.empty() && time.top().first.first <= t) {
                      auto curr = time.top();
                      time.pop();
                      aval.push({curr.first.second, curr.second});
                  }
      
                  if (!aval.empty()) {
                      auto [processingTime, index] = aval.top();
                      aval.pop(); 
                      t += processingTime;   
                      ans.push_back(index);
                  } else if (!time.empty()) {
                      t = time.top().first.first;
                  }
              }
              return ans;
          }
      };
