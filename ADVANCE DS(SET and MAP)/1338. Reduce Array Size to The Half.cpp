//PROBLEM :

      You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.
      
      Return the minimum size of the set so that at least half of the integers of the array are removed.



//APPROACH :
      To select the least and optimal element we just have to select the elements with maximum frequence
        ex for an array     7 7 7 7 7 7 3 3 3 3 3 2
        we can either select 3,2 both or just 7 is enough for the result



//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)



//CODE :
      class Solution {
      public:
          int minSetSize(vector<int>& arr) {
              unordered_map<int,int>mp;
              for(int i : arr) mp[i]++;
              priority_queue<int>pq;
              for(auto it:mp) {
                  pq.push(it.second);
              }
              int n = arr.size()/2;
              int ans = 0;
              while(!pq.empty() && n > 0) {
                  n -= pq.top();
                  ans++;
                  pq.pop();
              }
              return ans;
          }
      };
            
             
