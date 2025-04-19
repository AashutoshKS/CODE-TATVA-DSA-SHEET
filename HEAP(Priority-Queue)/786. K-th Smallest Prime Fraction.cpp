//PROBLEM :

              You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.
              
              For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].
              
              Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].


//APPROACH 1 : BRUTE FORCE

              Find all pair, store in a list, sort the list, return list[k-1]


//COMPLEXITY :
              TIME COMPLEXITY : O(2*n*n + n.logn) = O(n*n)
              SPACE COMPLEXITY : O(n*n)


//CODE :

              class Solution {
              public:
                  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
                      vector<float>ans;
                      for(int i=0;i<arr.size();i++){
                          for(int j=i+1;j<arr.size();j++){
                              float num=(arr[i]*1.0)/arr[j];
                              ans.push_back(num);
                          }
                      }
                      
                      sort(ans.begin(),ans.end());
                      float req=ans[k-1];
                      for(int i=0;i<arr.size();i++){
                          for(int j=i+1;j<arr.size();j++){
                              float che=(arr[i]*1.0)/arr[j];
                              if(che==req){
                                  return {arr[i],arr[j]};
                              }
                          }
                      }
                      return {};
                  }
              };


-------------------------------------------------------------------------------------------------------------------------------------------------------------

  
//APPROACH 2 : USING MAX HEAP
              Push all the pairs and fraction in max heap
              if size of heap exceeds k 
              pop the top element


//COMPLEXITY :
              TIME COMPLEXITY : O(n*n)
              SPACE COMPLEXITY : O(3*k) = O(k)


//CODE :
              class Solution {
              public:
                  vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
                      priority_queue<pair<float, pair<int, int>>> pq;
                      for (int i = 0; i < arr.size(); i++) {
                          for (int j = i + 1; j < arr.size(); j++) {
                              float num = (arr[i] * 1.0) / arr[j];
                              pq.push({num, {arr[i], arr[j]}});
                              if (pq.size() > k)
                                  pq.pop();
                          }
                      }
                      if (pq.size() < k)
                          return {};
                      return {pq.top().second.first, pq.top().second.second};
                  }
              };
                                           
