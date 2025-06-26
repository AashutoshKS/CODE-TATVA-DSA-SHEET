//PROBLEM :

      There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
      
      You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith 
      trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. 
      The locations are given as the number of kilometers due east from the car's initial location.
      
      Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.



//APPPROACH :
      for Each trip: [numPassengers, from, to]
      add numPassengers at time from, subtract numPassengers at time to
      store them either in a vector and sort it, or use min heap


//COMPLEXITY :
      TIME COMPLEXITY : O(n);
      SPACE COMPLEXITY : O(2*n) = O(n);


//CODE using list
      
      class Solution {
      public:
          bool carPooling(vector<vector<int>>& trips, int capacity) {
              vector<pair<int, int>> events;
              for (auto& trip : trips) {
                  events.push_back({trip[1], trip[0]});   
                  events.push_back({trip[2], -trip[0]});  
              }
              sort(events.begin(), events.end());
              int curr = 0;
              for (auto& e : events) {
                  curr += e.second;
                  if (curr > capacity) return false;
              }
              return true;
          }
      };


//CODE USING MIN HEAP

      class Solution {
      public:
          bool carPooling(vector<vector<int>>& trips, int capacity) {
              priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>>pq;
              for (auto& trip : trips) {
                  pq.push({trip[1], trip[0]});   
                  pq.push({trip[2], -trip[0]});  
              }
              int curr = 0;
              while(!pq.empty()) {
                  curr += pq.top().second;
                  if (curr > capacity) return false;
                  pq.pop();
              }
              return true;
          }
      };
