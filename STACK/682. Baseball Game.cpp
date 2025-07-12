//PROBLEM :

      You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.
      
      You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:
      
      An integer x.
      Record a new score of x.
      '+'.
      Record a new score that is the sum of the previous two scores.
      'D'.
      Record a new score that is the double of the previous score.
      'C'.
      Invalidate the previous score, removing it from the record.
      Return the sum of all the scores on the record after applying all the operations.
      
      The test cases are generated such that the answer and all intermediate calculations fit in a 32-bit integer and that all operations are valid.



//APPROACH :
      simple operations for charectors
      you can either use a stack or a list


//CODE :
      class Solution {
      public:
          int calPoints(vector<string>& operations) {
              vector <int> v;
              int score=0,j=0;
              for(int i=0;i<operations.size();i++){
                  if(operations[i]=="+"){
                      if(v.size()==0)
                      v.push_back(0);
                      else if(v.size()==1)
                      v.push_back(v[0]);
                      else
                      v.push_back(v[j-1]+v[j-2]);
                      j++;
                  }
                  else if(operations[i]=="D"){
                      if(v.size()==0){
                          v.push_back(0);
                          j++;
                      }
                      else{
                          v.push_back(2*v[j-1]);
                          j++;
                      }
                  }
                  else if(operations[i]=="C"){
                      v.pop_back();
                      j--;
                  }
                  else{
                      int x=stoi(operations[i]);
                      v.push_back(x);
                      j++;
                  }
              }
              for(int k=0;k<v.size();k++)
              score+=v[k];
              return score;
          }
      };
