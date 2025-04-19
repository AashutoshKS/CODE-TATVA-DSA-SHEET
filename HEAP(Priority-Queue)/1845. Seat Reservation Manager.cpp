//PROBLEM :

                  Design a system that manages the reservation state of n seats that are numbered from 1 to n.
                  
                  Implement the SeatManager class:
                  
                  SeatManager(int n) Initializes a SeatManager object that will manage n seats numbered from 1 to n. All seats are initially available.
                  int reserve() Fetches the smallest-numbered unreserved seat, reserves it, and returns its number.
                  void unreserve(int seatNumber) Unreserves the seat with the given seatNumber.



//APPROACH :
                we can use data structure like set, map, or vector
                        -> but finding the minimum element will take longer complexity
                Thus use Min Heap in order to keep track of minimum number unreserved


//CODE :
                class SeatManager {
                public:
                    priority_queue<int,vector<int>,greater<>>pq;
                    SeatManager(int n) {
                        for(int i = 1;i <= n; i++){
                            pq.push(i);
                        }
                    }
                    
                    int reserve() {
                        int x = pq.top();
                        pq.pop();
                        return x;
                    }
                    
                    void unreserve(int seatNumber) {
                        pq.push(seatNumber);
                    }
                };
