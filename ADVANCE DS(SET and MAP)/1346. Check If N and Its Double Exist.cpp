//PROBLEM :
    
      Given an array arr of integers, check if there exist two indices i and j such that :
      
      i != j
      0 <= i, j < arr.length
      arr[i] == 2 * arr[j]


//APPROACH 1:
      Use BRUTE FORCE to check all pairs....


//COMPLEXITY : 
      TIME COMPLEXITY : O(n*n)
      SPACE COMPLEXITY : O(1)



//CODE :
      class Solution {
      public:
          bool checkIfExist(vector<int>& arr) {
              for(int i=0;i<arr.size();i++){
                  for(int j=0;j<arr.size();j++){
                      if(i==j) continue;
                      else{
                          if(arr[i]==2*arr[j]){
                              return true;
                          }
                      }
                  }
              }
              return false;
          }
      };


//APPROACH 2 :
      USE MAP tp check if the number double or half exist or not


//COMPLEXITY :
      TIME COMPLEXITY : O(n)
      SPACE COMPLEXITY : O(n)


//CODE :
      class Solution {
      public:
          bool checkIfExist(vector<int>& arr) {
              map<int,int>mp;
              for(int i = 0 ;i < arr.size();i++) {
                  if(mp[arr[i]*2] != 0) return true;
                  if(arr[i]%2 == 0 && mp[arr[i]/2] != 0) return true;
                  mp[arr[i]]++;
                  
              }
              return false;
          }
      };
