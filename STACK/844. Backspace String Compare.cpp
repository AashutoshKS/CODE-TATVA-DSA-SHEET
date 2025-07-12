//PROBLEM :

      Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
      
      Note that after backspacing an empty text, the text will continue empty.



//APPROACH :
        create both the new string performing the backspace for each #
        return string1 = string2



//CODE:
      class Solution {
      public:
          bool backspaceCompare(string s, string t) {
              string ans1="";
              for(int i=0;i<s.size();i++){
                  if(!ans1.empty() && s[i]=='#')
                  ans1.pop_back();
                  else if(s[i]!='#')
                  ans1.push_back(s[i]);
              }
              s="";
              for(int i=0;i<t.size();i++){
                  if(!s.empty() && t[i]=='#')
                  s.pop_back();
                  else if(t[i]!='#')
                  s.push_back(t[i]);
              }
              return ans1==s ? 1 : 0;
          }
      };
      
