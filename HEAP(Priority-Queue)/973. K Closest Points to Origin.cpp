//PROBLEM :

              Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
              
              The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).
              
              You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).



//APPROACH :
              Use distance formula 
                  ie. distance between 2 ponts (x1,y1) ans (x2,y2) = sqrt((x2-x1)^2 + (y2-y1)^2)
              since one of point is origin ie. (0,0)
                the distance formula changes to sqrt(x1*x1 + y1*y1)
              Store the dis in min heap
              return top k pairs


//COMPLEXITy :
              TIME COMPLEXITY : O(n + k) = O(n)
              SPACE COMPLEXITY : O(n + k) = O(n)



//CODE :


              class Solution {
              public:
                  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
                      priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<double,vector<int>>>>heap;
                      for(int i=0;i<points.size();i++){
                          double x2 = (points[i][0]*points[i][0]);
                          double y2 = (points[i][1]*points[i][1]);
                          double in_val = x2 + y2;
                          double distance=sqrt(in_val);
                          heap.push({distance,points[i]});
                      }
                      vector<vector<int>>ans;
                      while(k--) {
                          ans.push_back(heap.top().second);
                          heap.pop();
                      }
                      return ans;
                  }
              };
                          
                           
