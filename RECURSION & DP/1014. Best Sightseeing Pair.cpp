//PROBLEM :

      You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i 
        between them.
      
      The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between 
        them.
      
      Return the maximum score of a pair of sightseeing spots.



//APPROACH :
      values[i] + values[j] + i - j = (values[i] + i) + (values[j] - j)



//CODE :

      class Solution {
       public:
        int maxScoreSightseeingPair(vector<int>& values) {
              int ans=0;
              int maxi=values[0];
              for(int i=1;i<values.size();i++){
                  ans=max(ans,maxi + values[i] - i);
                  maxi=max(maxi,values[i] + i);
              }
              return ans;
          }
      };        
