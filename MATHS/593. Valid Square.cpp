//PROBLEM :

      Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.
      
      The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.
      
      A valid square has four equal sides with positive length and four equal angles (90-degree angles).


//APPROACH :
      Find all the 6 distance of pairs using distance formula
      dis = (x2-x1)^2 + (y2-y1)^2
      For a square out of the 5
        -> 4 must me equal (side)
        -> rest 2 must be equal (diagonal)


//CODE :
      class Solution {
      public:
          long long distance(vector<int>num1, vector<int>num2) {
              long long dis = pow((num2[1] - num1[1]),2) + pow((num2[0] - num1[0]),2);
              return dis;
          }
          bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
              vector<vector<int>>nums{p1,p2,p3,p4};
              unordered_map<long long,int>mp;
              for(int i = 0;i < 4;i++) {
                  for(int j = i + 1;j < 4;j++) {
                      long long dis = distance(nums[i],nums[j]);
                      if(dis == 0) return false;
                      mp[dis]++;
                  }
              }
              if(mp.size() != 2) return false;
              for(auto it : mp) {
                  if(it.second == 2 || it.second == 4) return true;
              }
              return false;
          }
      };
