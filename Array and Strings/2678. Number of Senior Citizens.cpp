//PROBLEM : 
        You are given a 0-indexed array of strings details. Each element of details provides information about a given passenger compressed into a string of length 15. 
        The system is such that:
        
        The first ten characters consist of the phone number of passengers.
        The next character denotes the gender of the person.
        The following two characters are used to indicate the age of the person.
        The last two characters determine the seat allotted to that person.
        Return the number of passengers who are strictly more than 60 years old


//COMPLEXITY : 
    TIME COMPLEXITY : O(n)
    SPACE COMPLEXITY : O(1)



//CODE

class Solution {
public:
    int countSeniors(vector<string>& d) {
        int ans=0;
        for(int i=0;i<d.size();i++){
            int age=( (d[i][11]-'0')*10 )+(d[i][12]-'0');
            if(age>60){
                ans++;
            }
        }
        return ans;
    }
};
