//PROBLEM :
                You start with an initial power of power, an initial score of 0, and a bag of tokens given as an integer array tokens, 
                where each tokens[i] denotes the value of tokeni.
                
                Your goal is to maximize the total score by strategically playing these tokens. In one move, you can play an unplayed token in 
                one of the two ways (but not both for the same token):
                
                Face-up: If your current power is at least tokens[i], you may play tokeni, losing tokens[i] power and gaining 1 score.
                Face-down: If your current score is at least 1, you may play tokeni, gaining tokens[i] power and losing 1 score.
                Return the maximum possible score you can achieve after playing any number of tokens.


//APPROACH : 2 pointer, Sorting

              you have to maximise the score you can use the token if you have that much of power
              if you think greedily you will have a maximum score when
                    -> you lose minimum strenght
                    -> gain maximum strengt
              which is possible by picking alternate values using 2 pointer 
              sort the array and have 2 pointer in start and end
              
              if you are have more score than the current index value then increment your score losing token[i] points 
              but, If you do not havd that much power and you have to have maximum power 
              you will gain the power of token[j] and increment your score


//COMPLEXITY : 
              TIME COMPLEXITY : O(n.logn)
              SPACE COMPLEXITY : O(1)



//CODE :
              class Solution {
              public:
                  int bagOfTokensScore(vector<int>& tokens, int power) {
                      sort(tokens.begin(), tokens.end());
                      if (tokens.size() > 0 && tokens[0] > power) {
                          return 0;
                      }
                      int i = 0, j = tokens.size() - 1;
                      int max_score = 0, score = 0;
                      while (i <= j) {
                          if (power >= tokens[i]) {
                              score += 1;
                              power -= tokens[i];
                              i++;
                          } else {
                              power += tokens[j];
                              score--;
                              j--;
                          }
                          max_score = max(score, max_score);
                      }
                      return max_score;
                  }
              };
