//PROBLEM :
                You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum 
                weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
                
                Return the minimum number of boats to carry every given person.


//APPROACH : GREEDY/2-pointer/SORTING
                  sort the array
                  we can at most pick 2 element which must be maximum + minimum -> in order to utlise maximum space in boat
                  use 2 pointer to count the total number of required boats


//COMPLEXITY :
                  TIME COMPLEXITY : O(n.logn)
                  SPACE COMPLEXITY : O(1)



//CODE
                  class Solution {
                  public:
                      int numRescueBoats(vector<int>& people, int limit) {
                          sort(people.begin(),people.end());
                          int i=0;
                          int j=people.size()-1;
                          int count=0;
                          while(i<=j){
                              if((people[i]+people[j])>limit){
                                  count++;
                                  j--;
                              }
                              else{
                                  count++;
                                  i++;
                                  j--;
                              }
                          }
                          return count;
                      }
                  };
