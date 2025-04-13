//PROBLEM :

                Given a string s consisting only of characters a, b and c.
                
                Return the number of substrings containing at least one occurrence of all these characters a, b and c.



//APPROACH :
                Once you got all the 3 charectors add minimum poition of the 3 charectors to answer


//COMPLEXITY :
                TIME COMPLEXITY : O(n)
                SPACE COMPLEXITY : O(1)



//CODE :

                class Solution {
                public:
                    int numberOfSubstrings(string s) {
                        int a=0,b=0,c=0,count=0;
                        for(int i=0;i<s.size();i++){
                            if(s[i]=='a'){
                                a=i+1;
                            }
                            else if(s[i]=='b'){
                                b=i+1;
                            }
                            else if(s[i]=='c'){
                                c=i+1;
                            }
                            if(c>0 && a>0 && b>0){
                                count += min({a,b,c});
                            }
                        }
                        return count;
                    }
                };
