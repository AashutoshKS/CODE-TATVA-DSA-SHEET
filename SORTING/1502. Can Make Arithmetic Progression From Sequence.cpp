
//PROBLEM :
              A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.
              
              Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.



//APPROACH :
                A sequence will be in AP if either it is increasing or decreasing
                -> simply sort the vector and check if its in AP or not


//CODE :
              class Solution {
              public:
                  bool canMakeArithmeticProgression(vector<int>& arr) {
                      sort(arr.begin(),arr.end());
                      int count =2;
              
                      for(int i=1; i < arr.size()-1;i++){
                          if((arr[i]-arr[i-1]) == (arr[i+1]-arr[i]))
                             count++;
                      }
                      if(count==arr.size())
                          return true;
                      return false;
                  }
              };
