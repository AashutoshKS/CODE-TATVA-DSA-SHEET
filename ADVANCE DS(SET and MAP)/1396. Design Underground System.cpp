//PROBLEM :

      An underground railway system is keeping track of customer travel times between different stations. They are using this data to calculate the average time it takes to travel from one station to another.
      
      Implement the UndergroundSystem class:
      
      void checkIn(int id, string stationName, int t)
      A customer with a card ID equal to id, checks in at the station stationName at time t.
      A customer can only be checked into one place at a time.
      void checkOut(int id, string stationName, int t)
      A customer with a card ID equal to id, checks out from the station stationName at time t.
      double getAverageTime(string startStation, string endStation)
      Returns the average time it takes to travel from startStation to endStation.
      The average time is computed from all the previous traveling times from startStation to endStation that happened directly, meaning a check in at startStation followed by a check out from endStation.
      The time it takes to travel from startStation to endStation may be different from the time it takes to travel from endStation to startStation.
      There will be at least one customer that has traveled from startStation to endStation before getAverageTime is called.
      You may assume all calls to the checkIn and checkOut methods are consistent. If a customer checks in at time t1 then checks out at time t2, then t1 < t2. All events happen in chronological order.



//APPROACH :
      USe 2 maps...
              1 -> store the id that enters and exits any station
              2 -> store the total time and count of travels from a station a to station b taking key = "a-b"




//CODE :
      class UndergroundSystem {
      public:
          //id -> station, time
          map<int,pair<string, int>>mp;
          map<string, pair<int, int>>mp2;
          //from to -> time, count
          void checkIn(int id, string stationName, int t) {
              mp[id] = {stationName, t};
          }
          
          void checkOut(int id, string stationName, int t) {
              int reached = mp[id].second;
              string station = mp[id].first;
              string s = station + "-" + stationName;
              if (mp2.find(s) != mp2.end()) {
                  int v1 = mp2[s].first;
                  int v2 = mp2[s].second;
                  mp2[s] = {v1 + t - reached, v2 + 1};
              } else {
                  mp2[s] = {t - reached, 1};
              }
          }
          
          double getAverageTime(string startStation, string endStation) {
              string s = startStation + "-" + endStation;
              double total = mp2[s].first;
              double count = mp2[s].second;
              return total/count;
          }
      };
      
