//PROBLEM :

    You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
    The digits are ordered from most significant to least significant in left-to-right order. The large integer does not 
    contain any leading 0's.
    
    Increment the large integer by one and return the resulting array of digits.


//APPROACH :
      add 1 in the last element
      the exception in unit we get 9 as the last element
      if we till we encounter 9 change all the numbers to 0
        ie 34999
        become 35000 (9 -> 0, 3 + 1 = 4)



//CODE :

      class Solution {
      public:
          vector<int> plusOne(vector<int>& digits) {
              int n=digits.size();
              if(digits[n-1]!=9){
                  digits[n-1]++;
                  return digits;
              }
              int i=n-1;
              while(i>=0){
                  if(digits[i]==9 && i==0){
                      digits[0]=0;
                      digits.insert(digits.begin(),1);
                      break;
                  }
                  else if(digits[i]==9){
                      digits[i]=0;
                      i--;
                  }
                  else{
                      digits[i]++;
                      break;
                  }
              }
              return digits;
          }
      };
       
