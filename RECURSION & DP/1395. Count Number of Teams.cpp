//PROBLEM :

      There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
      
      You have to form a team of 3 soldiers amongst them under the following rules:
      
      Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
      A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
      Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).



//APPROACH :
      Try using brute force with some modifications


//CODE :
      class Solution {
      public:
          int numTeams(vector<int>& rating) {
              int count=0;
              int n=rating.size();
              for(int i=0;i<rating.size();i++){
                  for(int j=i+1;j<rating.size();j++){
                      if(rating[i]==rating[j]){
                          i = j - 1;
                          break;
                      }
                      for(int k=j+1;k<rating.size();k++){
                          if(rating[i] > rating[j] && rating[j] > rating[k]){
                              count++;
                          }
                          if(rating[i] < rating[j] && rating[j] < rating[k]){
                              count++;
                          }
                      }
                  }
              }
              return count;
          }
      };        
