//PROBLEM :

      You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
        Check if these points make a straight line in the XY plane.


//APPROACH :
        find slope of any 2 points
        for points to be strainght line
        slope of all the pairs should be equal
        if you encounter diffrent slope return false


//CODE :
      class Solution {
      public:
          bool checkStraightLine(vector<vector<int>>& num) {
              int x0=num[0][0];
              int y0=num[0][1];
              int x1=num[1][0];
              int y1=num[1][1];
              int dx=x1-x0;
              int dy=y1-y0;
              for(int i=0;i<num.size();i++){
                  int x=num[i][0];
                  int y=num[i][1];
                  if((y - y0)*dx!=(x - x0)*dy){
                      return false;
                  }
              }
              return true;
          }
      };
              
       
