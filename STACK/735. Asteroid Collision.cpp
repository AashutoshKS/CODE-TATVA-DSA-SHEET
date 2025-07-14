//PROBLEM :

      We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.
      
      For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid 
      moves at the same speed.
      
      Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. 
      Two asteroids moving in the same direction will never meet.




//CODE : BRUTE 
    deleting all asteroids one by one


      class Solution {
      public:
          vector<int> asteroidCollision(vector<int>& asteroids) {
              for(int i=0,j=i+1;i>=0 && j<asteroids.size();){
                  if(asteroids[i]*asteroids[j] < 0  && asteroids[i] > asteroids[j]){
                          if(abs(asteroids[i]) > abs(asteroids[j])){
                              asteroids.erase(asteroids.begin()+j);
                          }
                          else if(abs(asteroids[i]) < abs(asteroids[j])){
                              asteroids.erase(asteroids.begin()+i);
                          }
                          else{
                              asteroids.erase(asteroids.begin()+j);
                              asteroids.erase(asteroids.begin()+i);
                          }
                          if(i==0);
                          else{
                              i--;
                              j--;
                          }
                  }
                  else{
                      i++;
                      j++;
                  }
              }
              return asteroids;
          }
      };
