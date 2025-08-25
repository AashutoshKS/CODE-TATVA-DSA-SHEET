//PROBLEM : 

        The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either 
          prefers square or circular sandwiches.
        
        The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:
        
        If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
        Otherwise, they will leave it and go to the queue's end.
        This continues until none of the queue students want to take the top sandwich and are thus unable to eat.
        
        You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the 
        preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.



//APPROACH :
      Look if the students are in a queue and the chance for choosing will rotate ...............
      then a perticular student will always get his desired choice **only if the top of stack is the choice element
      check if you can follow the order of the stack,

      if at any index you can not fullfill the need of any student the remaining will not get their desired snadwitch




//COMPLEXITY :
      TIME COMPLEXITY : O(2n) = O(n)
      SPACE COMPLEXITY : O(1)




//CODE :
      class Solution {
      public:
          int countStudents(vector<int>& students, vector<int>& sandwiches) {
              int num1 = 0, num0 = 0;
              for (int i = 0; i < students.size(); i++) {
                  if (students[i] == 0)
                      num0++;
                  else
                      num1++;
              }
              int n = 0, size = sandwiches.size();
              for (int j = 0; j < sandwiches.size(); j++) {
                  if (sandwiches[j] == 1) {
                      if (num1 == 0)
                          return size - n;
                      else {
                          n++;
                          num1--;
                      }
                  } else if (sandwiches[j] == 0) {
                      if (num0 == 0)
                          return size - n;
                      else {
                          n++;
                          num0--;
                      }
                  }
              }
              return size - n;
          }
      };
